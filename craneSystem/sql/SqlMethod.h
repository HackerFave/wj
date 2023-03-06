#pragma once
#include "sqlOperation.h"
class sqlOperation;
class SqlMethod
{
public:
    SqlMethod();
    ~SqlMethod();
    static SqlMethod* sqlmethod_instance();
    static bool sqloperation_init(const std::string &point);
    sqlOperation *getsqloperationinstance(const std::string &point) {
		if (sqloperation_init(point)) {
			return p_sqloperation_;
		}
		return nullptr;
    }
private:
    static SqlMethod* p_sqlmethod_;
    static std::map<std::string, sqlOperation*> sqloperation_map_;
    static sqlOperation *p_sqloperation_;//当前操作实例

};

