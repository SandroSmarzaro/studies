# Compilação kernel 2021 Fedora Server 34

wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.12.7.tar.xz

dnf install ncurses-devel make gcc bc bison flex elfutils-libelf-devel openssl-devel perl dwarves

cp linux-5.12.7.tar.xz /usr/src/kernels/

cd /usr/src/kernels/

tar -Jxvf linux-5.12.7.tar.xz

cd linux-5.12.7/

cp -v /boot/config-5.8.15-301.fc33.x86_64 .config

make menuconfig

#Extraversion editing
vim Makefile

make

make modules

make modules_install

make install