![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de personas en secuencias de imágenes o video

**Alumnos:**

* Cristopher Ávalos Chavez (Coordinador)
* Cristóbal Ríos Chirino (Bitacora)

## Resumen 

<El Taller al que damos comienzo nos solicita un sistema de reconocimiento de personas. Para esta entrega en particular se solicita un programa que con ayuda de la biblioteca OpenCV podamos 
 detectar las personas en pantalla sea en una imagen, video o la cámara de seguridad en el contexto de lo que se nos solicita, marcando esta en un rectángulo de color en rojo, con el objetivo 
 de que un guardia tengan acceso a los datos recopilados de las personas que ingresaron o salieron del lugar. Para lograr este objetivo instalamos la IDE Visual Studio  2022 junto a OpenCV e 
 hicimos uso de las librerías que nos permiten usar los archivos que reconocen las personas y sus distintas herramientas. Una vez que obtuvimos todo lo necesario hicimos el código a partir de
 lo aprendido en los videos y obtuvimos las imágenes de los archivos que el profesor Juan Bekios nos facilito para hacer pruebas las cuales resultaron con éxito.>

## 1. Introducción

En los últimos años, la tecnología a avanzando de manera agigantada incluso llegando a nuestro dia a dia como es el caso de los smartphones. El reconocimiento de personas no se queda atrás,
y las personas que dediquen su tiempo en aprender en investigar estas tecnologías, tendran una ventaja en ciertas situaciones en la actualidad. Para obtener estos conocimientos hace falta
un proyecto que coloque a la persona a investigar sobre esta tecnología, como es el caso de este taller, el cual hará mejorar las habilidades y habituar.

Este taller trata de aprender a usar programas junto con herramientas que facilitan el reconocimiento de personas para lograr un objetivo que se establecen en los puntos posteriores los que 
tienen relación con el poder de observar personas por las cámaras con el fin de llevar un registro de sus movimientos (entrada o salida) dentro de algún lugar. Para llevar a cabo los objetivos
que planteamos más adelante se tendrá que recurrir a foros e investigar en detalle como usar las herramientas que nos proporcionan para trabajar de una manera eficaz y de esa manera podeer 
enfrentar todos los inconvenientes que se presenten.

### 1.1 Descripción del problema

Se nos presenta el caso, en el cual tenemos que construir un programa en el cual tiene que reconocer a personas en imágenes o videos con el fin de identificar a cada persona que ingresa o sale
de un lugar, y saber la cantidad de personas que realizan estas acciones. Esta información es de suma importancia para el guardia del lugar, y es por esto que el programa tiene que funcionar
sin error alguno.

### 1.2 Objetivos 

Contruir un programa que detecte en una imagen/video a las personas, e identidique a estas en un rectangulo de color rojo.

**Objetivos específicos**
1. Instalacion de la IDE Visual Studio, investigacion e instalacion de la biblioteca OpenCV y la herramienta CMaker.
2. Contar cuantas personas entran y salen de un lugar.
3. Calcular la velocidad a la cual las personas entras y salen de un lugar.
4. Contar las personas diferentes que han entrado y salido de un lugar.


### 1.3 Solución propuesta

Construir un programa que permita reconocer a personsa con el motivo de poder dar respuesta a los requerimientos del guardia y que de esta manera,
con los datos que se recolectan, como la cantidad de personas, la velocidad de personas para obtener el flujo, y las personas diferentes que han 
transitado, este guardia pueda desarrollar de manera eficiente su trabajo.

## 2. Materiales y métodos

* IDE Visual Studio Community 2022.
* Biblioteca OpenCV.
* Imagen de personas.

Configurando adecuadamente la IDE Visual Studio Community 2022 con la libreria OpenCV, se lograra el primer paso y el mas basico para poder trabajar
con nuestro codigo todo esto de la mano del uso a orientacion a objetos, se podran analizar las imagenes y de esta manera reconocer a las personas.

### 2.1 Instalación

* IDE Visual Studio Community 2022: Es una IDE que tendra el codigo del taller en el cual se haran las pruebas de codigo hasta completar el objetivo.
		Cabe recalcar que esta IDE no es la que utilizamos desde un principio, ya se utilizo la IDE Visual Studio Code 2022 y tuvimos problema con 
		la libreria OpenCV y CMake, problema el cual nos obligo a cambiar de IDE.

* Biblioteca OpenCV: Líbrería libre de visión artificial que cuenta con la mayoria de las herramientas y líbrerias para una correcta compatibilidad con la IDE.

### 2.2 Diseño 

La primera el primer entregable las clases implementadas son las siguientes:
* Detector: Nos permite al ser reconocida ya la persona, que se cree un rectangulo a su alrededor.
* Nodo: Es creado para la implementacion de la LinkedList.
* Linked: Es una LinkedList implementada por medio de nodos que nos permitira almacenar a las pesonas detectadas.
* Persona: Contiene las caracteristcas del identificador y el centroide de cada persona detectada.


### 2.3 Implementación

#### Detector de Personas

Para el detector de personas se utiliza la clase Detector en el cual se convertira en una instancia de la clase Persona.

```c++
void Detector::toggleMode() { m = (m == Default ? Daimler : Default); }

string Detector::modeName() const { return (m == Default ? "Default" : "Daimler"); }

//Estoy recibiendo una imagen para retornar un vector de tipo persona
vector<Persona> Detector::detect(InputArray img) {
    vector<Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2, 2), Size(4, 4), 1.05, 2, false);
    else if (m == Daimler)
        hog_d.detectMultiScale(img, found, 1, Size(2, 2), Size(4, 4), 1.05, 3, true);

    // Convertir un objeto Rect a un objeto persona
    vector<Persona> personas;
```

### Creacion y ajuste de rectangulo de la persona

En estas lineas de codigo se obtendra el rectangulo que se le asignara a la persona con sus dimenciones con respecto
a la posicion del centroide.

```c++
	for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i) {
        Rect& r = *i;
        Persona p(r);
        personas.push_back(p);
    }
```

### Contador de Personas.

Con este codigo, se inicializan unas variables con el fin de almacenar la cantidad de personas. Dentro del codigo en el cual se reconocen las personas 
se coloco una condición con respecto a la posición dentro de la imagen.

```c++
int contadorEntrada = 0;
int contadorSalida = 0;
	...

	if (p.getXCentro() > 175) {
            contadorEntrada++;
        }
        else {
            contadorSalida++;
        }
```






## 3. Resultados obtenidos

![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de personas en secuencias de imágenes o video

**Alumnos:**

* Cristopher Ávalos Chavez (Coordinador)
* Cristóbal Ríos Chirino (Bitacora)

## Resumen 

<El Taller al que damos comienzo nos solicita un sistema de reconocimiento de personas. Para esta entrega en particular se solicita un programa que con ayuda de la biblioteca OpenCV podamos 
 detectar las personas en pantalla sea en una imagen, video o la cámara de seguridad en el contexto de lo que se nos solicita, marcando esta en un rectángulo de color en rojo, con el objetivo 
 de que un guardia tengan acceso a los datos recopilados de las personas que ingresaron o salieron del lugar. Para lograr este objetivo instalamos la IDE Visual Studio  2022 junto a OpenCV e 
 hicimos uso de las librerías que nos permiten usar los archivos que reconocen las personas y sus distintas herramientas. Una vez que obtuvimos todo lo necesario hicimos el código a partir de
 lo aprendido en los videos y obtuvimos las imágenes de los archivos que el profesor Juan Bekios nos facilito para hacer pruebas las cuales resultaron con éxito.>

## 1. Introducción

En los últimos años, la tecnología a avanzando de manera agigantada incluso llegando a nuestro dia a dia como es el caso de los smartphones. El reconocimiento de personas no se queda atrás,
y las personas que dediquen su tiempo en aprender en investigar estas tecnologías, tendran una ventaja en ciertas situaciones en la actualidad. Para obtener estos conocimientos hace falta
un proyecto que coloque a la persona a investigar sobre esta tecnología, como es el caso de este taller, el cual hará mejorar las habilidades y habituar.

Este taller trata de aprender a usar programas junto con herramientas que facilitan el reconocimiento de personas para lograr un objetivo que se establecen en los puntos posteriores los que 
tienen relación con el poder de observar personas por las cámaras con el fin de llevar un registro de sus movimientos (entrada o salida) dentro de algún lugar. Para llevar a cabo los objetivos
que planteamos más adelante se tendrá que recurrir a foros e investigar en detalle como usar las herramientas que nos proporcionan para trabajar de una manera eficaz y de esa manera podeer 
enfrentar todos los inconvenientes que se presenten.

### 1.1 Descripción del problema

Se nos presenta el caso, en el cual tenemos que construir un programa en el cual tiene que reconocer a personas en imágenes o videos con el fin de identificar a cada persona que ingresa o sale
de un lugar, y saber la cantidad de personas que realizan estas acciones. Esta información es de suma importancia para el guardia del lugar, y es por esto que el programa tiene que funcionar
sin error alguno.

### 1.2 Objetivos 

Contruir un programa que detecte en una imagen/video a las personas, e identidique a estas en un rectangulo de color rojo.

**Objetivos específicos**
1. Instalacion de la IDE Visual Studio, investigacion e instalacion de la biblioteca OpenCV y la herramienta CMaker.
2. Contar cuantas personas entran y salen de un lugar.
3. Calcular la velocidad a la cual las personas entras y salen de un lugar.
4. Contar las personas diferentes que han entrado y salido de un lugar.


### 1.3 Solución propuesta

Construir un programa que permita reconocer a personsa con el motivo de poder dar respuesta a los requerimientos del guardia y que de esta manera,
con los datos que se recolectan, como la cantidad de personas, la velocidad de personas para obtener el flujo, y las personas diferentes que han 
transitado, este guardia pueda desarrollar de manera eficiente su trabajo.

## 2. Materiales y métodos

* IDE Visual Studio Community 2022.
* Biblioteca OpenCV.
* Imagen de personas.

Configurando adecuadamente la IDE Visual Studio Community 2022 con la libreria OpenCV, se lograra el primer paso y el mas basico para poder trabajar
con nuestro codigo todo esto de la mano del uso a orientacion a objetos, se podran analizar las imagenes y de esta manera reconocer a las personas.

### 2.1 Instalación

* IDE Visual Studio Community 2022: Es una IDE que tendra el codigo del taller en el cual se haran las pruebas de codigo hasta completar el objetivo.
		Cabe recalcar que esta IDE no es la que utilizamos desde un principio, ya se utilizo la IDE Visual Studio Code 2022 y tuvimos problema con 
		la libreria OpenCV y CMake, problema el cual nos obligo a cambiar de IDE.

* Biblioteca OpenCV: Líbrería libre de visión artificial que cuenta con la mayoria de las herramientas y líbrerias para una correcta compatibilidad con la IDE.

### 2.2 Diseño 

La primera el primer entregable las clases implementadas son las siguientes:
* Detector: Nos permite al ser reconocida ya la persona, que se cree un rectangulo a su alrededor.
* Nodo: Es creado para la implementacion de la LinkedList.
* Linked: Es una LinkedList implementada por medio de nodos que nos permitira almacenar a las pesonas detectadas.
* Persona: Contiene las caracteristcas del identificador y el centroide de cada persona detectada.


### 2.3 Implementación

#### Detector de Personas

Para el detector de personas se utiliza la clase Detector en el cual se convertira en una instancia de la clase Persona.

```c++
void Detector::toggleMode() { m = (m == Default ? Daimler : Default); }

string Detector::modeName() const { return (m == Default ? "Default" : "Daimler"); }

//Estoy recibiendo una imagen para retornar un vector de tipo persona
vector<Persona> Detector::detect(InputArray img) {
    vector<Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, Size(2, 2), Size(4, 4), 1.05, 2, false);
    else if (m == Daimler)
        hog_d.detectMultiScale(img, found, 1, Size(2, 2), Size(4, 4), 1.05, 3, true);

    // Convertir un objeto Rect a un objeto persona
    vector<Persona> personas;
```

### Creacion y ajuste de rectangulo de la persona

En estas lineas de codigo se obtendra el rectangulo que se le asignara a la persona con sus dimenciones con respecto
a la posicion del centroide.

```c++
	for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i) {
        Rect& r = *i;
        Persona p(r);
        personas.push_back(p);
    }
```

### Contador de Personas.

Con este codigo, se inicializan unas variables con el fin de almacenar la cantidad de personas. Dentro del codigo en el cual se reconocen las personas 
se coloco una condición con respecto a la posición dentro de la imagen.

```c++
int contadorEntrada = 0;
int contadorSalida = 0;
	...

	if (p.getXCentro() > 175) {
            contadorEntrada++;
        }
        else {
            contadorSalida++;
        }
```






## 3. Resultados obtenidos

Una vez terminada la ejecución del programa esta nos arroja la imagen que habiamos preseleccionado cuyo son personas pero con 
la diferencia de que ahora estarían identificadas por el código, mostrando asi cinco rectángulos rojos en cada persona. Ademas cada persona,
tiene un identificado personal.

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

>Se descargo he instalo OpenCV y la carpeta bin se agrego a las variables de entorno del sistema para que el sistema reconozca donde ir a ejecutar los binarios referentes a OpenCV.

## Anexo B: Instalación de IDE y configuración librerías OpenCV

>Se descargo he instalo Visual Studio Community 2019. Una vez creado el proyecto vamos a propiedades de este y configuramos las líbrerias de OpenCV en Visual Studio. 
>Las líbrerias son las siguientes:
* Del directorio de VC++ (opencv\build\include) y (opencv\build\x64\vc15\lib)
* En la seccíon general de c++ agregamos el include siguiente (opencv\build\include\opencv2)


# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:



## 4. Conclusiones
