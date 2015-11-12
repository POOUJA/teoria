# Cambios respecto a ejemplo T_4_3_Ejemplares

* Se crea la clase Revista como especialización de Ejemplar
* La clase Ejemplar se convierte en abstracta haciendo virtual puro el método setID
** El atributo _identificador de Ejemplar pasa a ser protegido
** Libro y Revista pasan a implementar el método setID utilizando su ISBN o ISSN respectivamente
* Se crea la interfaz ItemCSV para reflejar clases cuyos objetos son capaces de trasformarse hacia y desde una cadena de de caracteres en formato CSV
** El método Visualiza un ejemplar se trasforma para aceptar sólo objetos que implementen la interfaz ItemCSV
** Se implementa la plantilla de función GuardaCSV para guardar en un fichero cualquier vector de punteros a objetos que implementen ItemCSV



