#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include "board.cpp"

pair <string, string>     new_board() {
    PGconn          *conn;
    PGresult        *res;
 
 
 
    conn = PQconnectdb("dbname=boggle user=postgres");
 
    if (PQstatus(conn) == CONNECTION_BAD) {
                 puts("We were unable to connect to the database");
                 exit(0);
    }
    string b = getBoard();
    string query = "INSERT INTO boards (letters) VALUES ( '";
    query += b;
    query += "')";
    query += " RETURNING board_id;";
    
    const char * c = query.c_str();
    
    res = PQexec(conn,  c);
    
    string a = PQgetvalue(res, 0, 0);
    
    PQclear(res);
    PQfinish(conn);
    return make_pair(a,b);
 }