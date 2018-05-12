/**
 * @brief: Water-it: Software for automated flower watering
 * @file: Database.cpp
 * @author: Tom Svoboda
 * @date: 8. 5. 2018
 */

#include "Database.h"
#include "../config.h"
#include <mysql++/mysql++.h>

using namespace Database;

/**
 * Construct database access object
 * @param server Server name or IP
 * @param database Name of database
 * @param user User for access
 * @param password Users password
 */
Database::Database(std::string server, std::string database, std::string user, std::string password) :
    server(server),
    database(database),
    user(user),
    password(password)
{}

/**
 * Return today Schedule
 * @param schedule Reference to schedule to fill
 */
bool Database::getSchedule(Schedule &schedule) {
    mysqlpp::Connection *db = connect();

    if(db == nullptr) {
        return false;
    }

    mysqlpp::Query query = db->query();
    query << "SELECT id, start_time, duration FROM `timetable` WHERE active=1 AND NOW() BETWEEN active_from AND active_to LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();

    /* Return if there is no result */
    if(!res || res.num_rows() == 0) {
        return false;
    }

    schedule.setFromString(res[0]["start_time"], res[0]["duration"]);
}

/**
 * Connect to database
 */
mysqlpp::Connection *Database::connect() {
    try {
        return new mysqlpp::Connection(database, server, user, password);
    }
    catch(std::exception &e) {
        DEBUG("Database", "Can't connect to database " << e.what());
        return nullptr;
    }
}

/**
 * Disconect from database
 */
void disconnect(mysqlpp::Connection *connection) {
    if(connection != nullptr) {
        delete connection;
    }
}
