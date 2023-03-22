# SO_Proyecto1
Syscall (expr_arit) de expresión aritmética

### Especificaciones del proyecto
Este proyecto trata sobre crear un syscall que resuelva una expresión aritmética. Se utlizan las siguientes herramientas: 
- Virtualbox
- Ubuntu 18. 
- El linux kernel (linux-5.6.1) que se compilará con el nuevo syscall es: https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/linux-5.6.1.tar.xz
    - El linux kernel que esté en la imagen de Ubuntu debe de ser inferior. Ya que si es superior, no permitirá la compilación de un nuevo kernel.
### Resumen de pasos
1. Verificar el linux con: uname -r
2. Descargar Konsole (para poder utilizar un terminal)
3. Dentro de Konsole, escribir el comando: su. Poner la contraseña del virtualbox
5. Entrar a la carpeta:  cd /usr/src/
6. Descargar el linux: wget https://mirrors.edge.kernel.org/pub/linux/kernel/v5.x/linux-5.6.1.tar.xz
7. Descomprimir la carpeta del linux: tar -xvf linux-5.6.1.tar.xz
8. Entrar a la carpeta del linuxL cd linux-5.6.1
9. Crear carpeta del nuevo Syscall, entrar a la misma: mkdir expr_arit, cd expr_arit
10. Crear el archvio .c que dará la definición del syscall: gedit expr_arit.c
    - Agregar archivo: files_linux/expr_arit archivo: expr_arit.c
    - save
11. Crear un archivo Makefile: gedit Makefile
    - agregar: obj-y:=expr_arit.o
    - save
    - salir un nivel cd ..
    - estar en linux-5.6.1
12. Entrar a modificar el archivo Makefile: gedit Makefile
    - ctrl+f: buscar core-y 
    - en el segundo core-y agregar: expr_arit/
    - save
13. Entrar a: cd include/linux
14. Entrar al archivo: gedit syscalls.h
    - Agregar protoripo: asmlinkage long expr_arit(char __user *ex, int *result);
    - save
    - cd ../..
15. Entrar a: cd arch/x86/entry/syscalls
    - entrar a modificar la tabla de syscalls: gedit syscall_64.tbl
  	- agregar syscall: 439 common expr_arit __x64_sys_expr_arit
    - save
    - cd ../../../../
    - Deberías de estar en linux
16. Install: 
    - apt install build-essential libssl-dev gcc bc bison flex libelf-dev libncurses5-dev dwarves
    - apt install gcc make libncurses-dev flex bison libssl-dev libelf-dev initramfs-tools-bin

17. Comando: cp /boot/config-$(uname -r) ./.confg

18. Dejar todo en default: make localmodconfig
    - enter
19. Compilar kernel: 
    - make deb-pkg
20. Salir a: 
    - cd ..
    - /src/     
    - correr comando: dpkg -i *.deb
21. reboot
22. Verificar el linux con: uname -r
    - su
    - cd /usr/src/
    - apt update && apt upgrade -y
    - apt autoremove
        - Y

### Run test
- Crear carpeta test, donde sea de su gusto. (Desktop, documents, downloads, etc.)
- Entrar a ella e insertar el archivo: 
    - test1.c
- Compilar archivo: gcc test1.c
- Correr archivo: ./a.out


Listo tienes un syscall que resuelve y valida expresiones aritméticas !!
