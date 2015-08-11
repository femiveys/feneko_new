#!/bin/bash

# Execute the file with the first parameter the prefix
# Execute without parameter will result in no prefix

SQL="tables.sql"
PREFIX="$1"
STMNT=`sed "s/feneko_/$PREFIX/" "$SQL"`
drush sqlq "$STMNT"
