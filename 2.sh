#!/bin/bash

# cat messages | grep 'Oct 16' | awk '{print $3}' | grep -E -c '03:1[5-9]:|03:[2-5][0-9]:|04:0[0-9]:|04:1[0-9]:' 
grep 'Oct 16' messages | grep -E -c '03:1[5-9]:|03:[2-5][0-9]:|04:0[0-9]:|04:1[0-9]:'
