#!/bin/bash

grep "eth0" messages | awk '{print $4}' | sort | uniq -c | sort -r
