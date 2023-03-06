#include "SqlMethod.h"

#include <map>
#include <qstring.h>
 SqlMethod* SqlMethod::p_sqlmethod_ = Q_NULLPTR;
 std::map<std::string, sqlOperation*> SqlMethod::sqloperation_map_;
 sqlOperation *SqlMethod::p_sqloperation_ = Q_NULLPTR;//当前操作实例

SqlMethod::SqlMethod()
{
}


SqlMethod::~SqlMethod()
{
    sqloperation_map_.clear();
}
 SqlMethod*SqlMethod::sqlmethod_instance() {
    if (!p_sqlmethod_) {
        p_sqlmethod_ = new SqlMethod;
    }
    return p_sqlmethod_;
}
bool SqlMethod::sqloperation_init(const std::string &point) {
    if (sqloperation_map_[point] != NULL) {
        p_sqloperation_ = sqloperation_map_[point];
		return true;
    }
    else
    {
        sqlOperation *sql = new sqlOperation(point);      
        if (sql->Init("127.0.0.1", "root", "123456", "crane")) {
            qInfo()<<QStringLiteral("初始化数据库成功!")<<point.c_str();  // \n表示换行<< point.toStdString().c_str() << ":" << "初始化数据库成功";
			p_sqloperation_ = sql;
			sqloperation_map_[point] = sql;
			return true;
        }
		return false;
    }

}
