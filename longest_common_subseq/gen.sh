#!/bin/bash
# bash generate random alphanumeric string
#
 
# bash generate random 32 character alphanumeric string (upper and lowercase) and 
cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $1 | head -n 1 >> $3
cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $2 | head -n 1 >> $3
