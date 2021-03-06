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

En los últimos años, la tecnología a avanzando de manera agigantada incluso llegando a nuestro dia a dia como es el caso de los smartphones el cual es un artefacto electronico que mediante una simple camara detecta cualquier tipo de objeto. El reconocimiento de personas no se queda atrás,
y las personas que dediquen su tiempo en aprender e investigar estas tecnologías, tendran una ventaja en ciertas situaciones en la actualidad. Para obtener estos conocimientos hace falta
un proyecto que coloque a la persona a investigar sobre esta tecnología, como es el caso de este taller, el cual hará mediante ciertos algoritmos e indagación profunda respecto al tema logrará con efectividad el reconocimientos de personas.

Este taller trata de aprender a usar programas junto con herramientas que facilitan el reconocimiento de personas con el fin de lograr un objetivo principal el cual 
tiene relación con el poder observar personas por las cámaras con el fin de llevar un registro de sus movimientos (entrada o salida) dentro de algún lugar. Para llevar a cabo los objetivos
que planteamos más adelante se tendrá que recurrir a foros e investigar en detalle como usar las herramientas que nos proporcionan para trabajar de una manera eficaz y de esa manera poder 
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
3. Creación de un arbol binario.
4. Calcular la velocidad de las personas que entran y salen de un lugar.
5. Calcular el tiempo de ejecución del programa


### 1.3 Solución propuesta

Construir un programa que permita reconocer a personas con el motivo de poder dar respuesta a los requerimientos del guardia y que de esta manera,
con los datos que se recolectan, como la cantidad de personas, la velocidad de personas para obtener el flujo, y las personas diferentes que han 
transitado, este guardia pueda desarrollar de manera eficiente su trabajo.
Construir un programa que permita el reconocimientos de personas usando la librería OpenCV y las distintas herramientas disponibles de esta para la detección de personas en imagenes, esto con el fin de cumplir con los requirimientos que se solicitan ya sea de un guardia o del mismo administrador. Entre los puntos a desarrollar esta la velocidad de las personas que entran y salen y  el reconomiento de personas que entran y salen.

Construir un programa que permita el reconocimiento de personas para poder dar respuesta a los requerimientos del guardia y de esta manera poder recolectar los datos solicitados. Entre estos datos está la cantidad de personas que entran y salen, y por otra parte la velocidad de las personas que entran y salen; de esta forma se podrá dar respuesta a lo solicitado. El uso de la librería OpenCV será de vital importancia ya que se usará las distintas herrramientas que esta librería tiene para la detección de personas en imagenes.Además del uso de la librería se ocupará una estructura jerarquica en este caso un arbol binario para ordenarlas las posiciones de las personas dentro de la imagen.

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
* NodoArbol : Nodo creado para ser implementado en el arbol binario.
* BinaryTree : Arbol binario el cual inicializa con un NodoArbol.
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

Lo que hace la funcion de contar nodos es contar los nodos del arbol de forma recursiva. Y junto con esto se integra la segunda función para ver si al momento de recorrer se encuentra algún nodo terminal.

```c++
int  BinaryTree::cuentaNodos(NodoArbol* nodo, int contador) {
	if (isLeaf(nodo)) {
		contador++;
	}
	if (nodo->izq != nullptr) {		
		contador = cuentaNodos(nodo->izq, contador);
		contador++;

	}
	if (nodo->der != nullptr) {
		contador = cuentaNodos(nodo->der, contador);		
		contador++;
	}
	return contador;
}

bool  BinaryTree::isLeaf(NodoArbol* nodo) {
	if (nodo->der == nullptr && nodo->izq == nullptr)
		return true;
	return false;
}
```
### Cantidad Personas Entrantes y Salientes.

En este caso para calcular la cantidad de personas que entran y salen, ocupamos la funcion de contarNodos.	
```c++
int BinaryTree::cantEntrantes() {
	int contador = 0;
	if (raiz != nullptr) {
		NodoArbol* n = raiz->izq;
		contador = cuentaNodos(n, contador);
	}
	return contador;
}

int BinaryTree::cantSalientes() {
	int contador = 0;
	if (raiz != nullptr) {
		NodoArbol* n = raiz->der;
		contador = cuentaNodos(n, contador);
	}
	return contador;
}
	
```		
### Calculo del tiempo de ejecución.

Con este codigo calculo el tiempo de ejecucion de cierto bloque, el cual esta implementado en el medio de la funcion declarando su tiempo inicial y luego tiempo final de la ejecucion.

```c++
    double tiempo = 0;
    clock_t inicio, fin;
    inicio = clock();
    //Bloque de ejecucion
    fin = clock();
    double time = (double(fin - inicio) / CLOCKS_PER_SEC);
    tiempo = time;
```
### Linea que indica la mitad de la imagen.
	
Esta linea lo que hace es centrarse a la mitad de la imagen, facilitandonos ver si la persona en la iamgen está saliendo o está entrando
```c++
Point p1(175, 0), p2(175, 300);
int time = 1;
line(imagen, p1, p2, Scalar(255, 0, 0), time, LINE_8);	
	
```
## 3. Resultados obtenidos
	
En lo que respecta a los resultados obtenidos se logró poder identificar las personas que van entrando o saliendo en la imagen correspondiente, mostrando dentro de la imagen los 3 rectangulos correspondientes a las personas detectadas, además del calculo de la velocidad de estas personas. Frente a esta resolucion de este sistema  hubo un problema a la hora de ejecutar el menu con la imagen dentro de este, ya que no reconocía el vector en donde se almacena la imagen. Debido a esto planteamos a última hora el inicio del programa de otra forma

## 4. Conclusiones
	
Para el desarrollo del sistema realizado se necesito variadas fuentes de informacion con el fin de investigar respecto a la librería OpenCV la cual era el eje principal para el desarrollo de este proyecto, además dentro de la ejecucion del programa hubo varios percances también respecto al uso de la IDE y de los "includes" correspondientes al lenguaje de programación C++. Por otra parte cabe recalcar que al principio incluimos la informacion de las personas en una LinkedList pero al ejecutar ciertos cambios planteamos el uso de una estructura jerarquica conocida como "Arboles Binarios" los cuales se nos hacía más facil interpretar así a las personas que estén entrando o saliendo a la hora de ejecutar el sistema. Respecto al objetivo principal se logro plasmar dentro de una imagen el reconocimiento de personas y con esto su ubicación dentro de la imagen para lograr ver si están saliendo o entrando al espacio físico de la imagen, pero al momento de ejecutar el programa final tuvimos un incoveniente el cual no imprímia la imagen para detectar las personas pero dentro del sistema si organizaba los datos de las personas detectadas por lo que tuvimos que hacer unos pequeños arreglos dentro del menú. Por último podemos decir que el desarrollo de este programa puede ser muy eficiente si se le da un enfoque mas a futuro.

# Anexos

## Anexo A: Instalación librerías OpenCV

>Se descargo he instalo OpenCV y la carpeta bin se agrego a las variables de entorno del sistema para que el sistema reconozca donde ir a ejecutar los binarios referentes a OpenCV.

## Anexo B: Instalación de IDE y configuración librerías OpenCV

>Se descargo he instalo Visual Studio Community 2019. Una vez creado el proyecto vamos a propiedades de este y configuramos las líbrerias de OpenCV en Visual Studio. 
>Las líbrerias son las siguientes:
* Del directorio de VC++ (opencv\build\include) y (opencv\build\x64\vc15\lib)
* En la seccíon general de c++ agregamos el include siguiente (opencv\build\include\opencv2)


# Referecia

Fusia, C., Quiroa, L., Silva, S., Wolukanis, F. V., Boulabiar, I., Babu, S., Alexandrou, F., & Chedella, P. (2021, 16 julio). Code OpenCV in Visual Studio. LearnOpenCV – OpenCV, PyTorch, Keras, Tensorflow Examples and Tutorials. https://learnopencv.com/code-opencv-in-visual-studio/
