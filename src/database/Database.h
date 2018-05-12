/**
 * @brief: Water-it: Software for automated flower watering
 * @file: Database.h
 * @author: Tom Svoboda
 * @date: 8. 5. 2018
 */

#ifndef DATABASE_H
#define DATABASE_H

namespace Database {

/**
 * Access to database
 */
class Database {
public:
    /**
     * Construct database access object
     * @param server Server name or IP
     * @param database Name of database
     * @param user User for access
     * @param password Users password
     */
    Database(std::string server, std::string database, std::string user, std::string password);

    /**
     * Return today Schedule
     * @param schedule Reference to schedule to fill
     */
    bool getSchedule(Schedule &schedule);

private:
    std::string server, database, user, password;

    /**
     * Connect to database
     */
    mysqlpp::Connection *connect();

    /**
     * Disconect from database
     */
    void disconnect(mysqlpp::Connection *connection);
};

}

#endif
