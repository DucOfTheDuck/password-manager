#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include "password_generator.h"

void save_password(const char *name, const char *password, const char *key);
void retrieve_password(const char *name, const char *key);
int list_password_names();

#endif