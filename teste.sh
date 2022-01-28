#!/bin/sh
 
# ********************** #
#    remontti.com.br     #
# ********************** #
 
# Porcentagem máxima (mude se você achar necessário)
percent=85
 
# Total da memoria:
ramtotal=`grep -F "MemTotal:" < /proc/meminfo | awk '{print $2}'`
# Memoria livre:
ramlivre=`grep -F "MemFree:" < /proc/meminfo | awk '{print $2}'`
 
# RAM utilizada pelo sistema:
ramusada=`expr $ramtotal - $ramlivre`
 
# Porcentagem de RAM utilizada pelo sistema:
putil=`expr $ramusada \* 100 / $ramtotal`
 
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
date
echo
echo "Mem. utilizada: $putil %";
 
if [ $putil -gt $percent ]
then
date=`date`
echo $date >> /var/log/memoria.log
echo "Mem. utilizada: $putil %" >> /var/log/memoria.log
 
echo "Memoria acima de $percent %, cache foi limpado!";
sync
# 'Dropando' cache:
echo 3 > /proc/sys/vm/drop_caches
# Caso nao esteja utilizanod debian, descomente a linha abaixo
 sysctl -w vm.drop_caches=3 
# Zera SWAP
swapoff -a
swapon -a
echo
free -m
echo
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
else
echo "Cache não foi limpado!";
echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unset percent ramtotal ramlivre ramusada putil
exit $?
fi