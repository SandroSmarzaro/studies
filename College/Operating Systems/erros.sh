
#------------------------------ssh error-------------------------------
vim /etc/ssh/sshd_config 
PermitRootLogin yes
service sshd restart

#-------------------------------error 127------------------------------
scripts/config --disable KERNEL_LZ4
scripts/config --enable KERNEL_GZIP
vim .config 
CONFIG_KERNEL_GZIP=y

#--------------------------------error 1-----------------------------------
vboxmanage modifyhd "C:\Users\User\VirtualBox VMs\Fedora Server\Fedora Server.vdi" --resize MB
df -h
lvscan
lvextend -L +resizeG /dev/mapper/centos-root
xfs_growfs /dev/mapper/centos-root