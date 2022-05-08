
/*Jos� Manuel P�rez Lobato
Ejemplo de utilizaci�n de la m�scara
comprobar su funcionamiento realizando un ls -l despu�s de su ejecuci�n
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {
  mode_t permisos, mascara_nueva, mascara_anterior;
  FILE *f;
  int fd;
 
  /* ponemos como mascara  rwxrwx--- = 0770 */
  mascara_nueva=S_IRUSR | S_IWUSR |S_IXUSR | S_IRGRP | S_IWGRP| S_IXGRP;
  mascara_anterior=umask (mascara_nueva);

  /* creamos un fichero tipo FILE *  */
  if ((f=fopen("nuevo_fich_str","w"))!= NULL) 
    fclose(f);

  /* creamos un fichero tipo descriptor con los permisos rw-r---w- =0642 */
  permisos =S_IRUSR|S_IWUSR|S_IRGRP|S_IWOTH;
  if ((fd=open("nuevo_fich_Des",O_CREAT, permisos))> 0) 
    close(fd);
  umask (mascara_anterior);
}
