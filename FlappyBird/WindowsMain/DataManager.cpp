#include "stdafx.h"
#include "DataManager.h"

static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void DataManager::Init()
{
    char* errMsg = 0;
    int rc;

    //---------------------------------------
    //	## DB Open
    //---------------------------------------
    {
        rc = sqlite3_open("client.db", &_db);

        if (rc != SQLITE_OK) {
            std::cerr << "[DataManager] Can't open database: " << sqlite3_errmsg(_db) << std::endl;
        }
        else {
            std::cout << "[DataManager] Opened database successfully" << std::endl;
        }
    }


    //---------------------------------------
    //	## Table Create
    //---------------------------------------
    {
        const char* sql =
            "CREATE TABLE IF NOT EXISTS TblCollisionData ( " \
            "_id 		INTEGER 	NOT NULL 	PRIMARY KEY 	AUTOINCREMENT " \
            ", _left	INTEGER 	NOT NULL " \
            ", _top 	INTEGER		NOT NULL " \
            ", _right	INTEGER 	NOT NULL " \
            ", _bottom	INTEGER 	NOT NULL "\
            "); ";

        // Execute SQL statement
        rc = sqlite3_exec(_db, sql, callback, 0, &errMsg);

        if (rc != SQLITE_OK) {
            std::cerr << "[DataManager] SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
        else {
            std::cout << "[DataManager] Table created successfully" << std::endl;
        }
    }


    this->GetCollisionData();
}
void DataManager::Release()
{
    sqlite3_close(_db);
}

void DataManager::SaveCollisionData(vector<RECT> rectVec)
{
    char* errMsg = 0;
    int rc;

    //---------------------------------------
    //	## Table Insert
    //---------------------------------------
    {
        string sql =
            "INSERT INTO TblCollisionData (_left, _top, _right, _bottom) "
            " VALUES ";

        if (rectVec.size() >= 1)
        {
            char str[256];
            sprintf_s(str, "(%d, %d, %d, %d)", 
                rectVec[0].left, 
                rectVec[0].top,
                rectVec[0].right,
                rectVec[0].bottom);
            sql += str;
        }

        for (int i = 1; i < rectVec.size(); i++)
        {
            char str[256];
            sprintf_s(str, ", (%d, %d, %d, %d)",
                rectVec[i].left,
                rectVec[i].top,
                rectVec[i].right,
                rectVec[i].bottom);
            sql += str;
        }

        // Execute SQL statement
        rc = sqlite3_exec(_db, sql.c_str(), callback, 0, &errMsg);

        if (rc != SQLITE_OK) {
            std::cerr << "[DataManager] SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
        else {
            std::cout << "[DataManager] Table Insert successfully" << std::endl;
        }
    }

    
}

void DataManager::ClearCollisionData()
{
    char* errMsg = 0;
    int rc;

    //---------------------------------------
    //	## Table Delete
    //---------------------------------------
    {
        string sql =
            "DELETE FROM TblCollisionData";

        // Execute SQL statement
        rc = sqlite3_exec(_db, sql.c_str(), callback, 0, &errMsg);

        if (rc != SQLITE_OK) {
            std::cerr << "[DataManager] SQL error: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
        else {
            std::cout << "[DataManager] Table Insert successfully" << std::endl;
        }
    }
}

vector<RECT> DataManager::GetCollisionData()
{
    _collisionDats.clear();
    //---------------------------------------
    //	## Table Select
    //---------------------------------------

    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql =
        "SELECT _left, "
        "       _top, "
        "       _right, "
        "       _bottom "
        "FROM TblCollisionData";

    rc = sqlite3_prepare_v2(_db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(_db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;

            int left = sqlite3_column_int(stmt, columnIndex++);
            int top = sqlite3_column_int(stmt, columnIndex++);
            int right = sqlite3_column_int(stmt, columnIndex++);
            int bottom = sqlite3_column_int(stmt, columnIndex++);

            RECT rc = { left, top, right, bottom };
            _collisionDats.push_back(rc);
        }
    }



    return _collisionDats;
}