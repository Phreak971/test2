#include <iostream>
#include <occi.h>

#define LOG() std::cout << __LINE__ << std::endl

int main()
{
  const std::string userName = "SYSTEM";
  const std::string password = "abc123ABC";
  const std::string connectString = "(DESCRIPTION =(ADDRESS = (PROTOCOL = TCP)(HOST = 127.0.1.1)(PORT = 1521)))";

  {
    oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
    {
      try
      {
        oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
        oracle::occi::Connection *conn = env->createConnection(userName, password, connectString);
        oracle::occi::Statement *stmt = conn->createStatement();
        //stmt->executeUpdate("CREATE TABLE shopping_basket(item_number VARCHAR2(30), quantity NUMBER(3))");
        //stmt->executeUpdate("INSERT INTO shopping_basket VALUES('MANGO', 3)");

        //stmt->executeUpdate("UPDATE shopping_basket SET quantity=1 WHERE item_number='MANGO'");
        //stmt->executeQuery("DELETE FROM shopping_basket");
        stmt->setSQL("SELECT * FROM shopping_basket");
        oracle::occi::ResultSet *rs = stmt->executeQuery();
        while (rs->next())
        {
          std::cout << rs->getString(1) << ", " << rs->getInt(2) << std::endl;
        }

        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
      }
      catch (oracle::occi::SQLException &e)
      {
        std::cout << e.what();
      }
    }
    oracle::occi::Environment::terminateEnvironment(env);
  }
}