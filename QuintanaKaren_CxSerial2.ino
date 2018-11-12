/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE
 *  Nombre: Karen Quintana
 *  Realizar un sistema que permite determinar el número de vocales dentro de una 
 *  palabra. Este dato es ingresado por comunicación serial y la respuesta del mismo de igual manera. 
 *  Subir su link de github. 
 *  Ejemplo 1: Ingreso: CIERCOM Retorna: 3 Ejemplo 2. Ingreso: DATOS Retorna: 2
 */
String palabra;
int tamP=0;// variable para el tamaño de la palabra a ingresar
int contV=0;// variable para contador de vocales
int i=0;// variable de conteo ó recorrido
void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese una palabra");//Solicitar Dato una vez para todo el programa
}

void loop() {
    
   while(Serial.available()>0){
    palabra=Serial.readString();//Lee palabra ingresada
    tamP=palabra.length();//conocer el tamaño del string
    for(i=0;i<=tamP;i++){// declaramos que la variable de conteo para recorrer toda la palabra
      if(palabra.charAt(i)=='a' ||palabra.charAt(i)=='e'||palabra.charAt(i)=='i'||//Evaluar caracter por caracter una cadena especificando el tipo de dato que queremos evaluar
      palabra.charAt(i)=='o'||palabra.charAt(i)=='u'||palabra.charAt(i)=='A' 
      ||palabra.charAt(i)=='E'||palabra.charAt(i)=='I'||palabra.charAt(i)=='O'
      ||palabra.charAt(i)=='U')// para leer vocales mayúsculas y minúsculas
    contV ++;// la variable para contador de vocales incrementa
    }
    Serial.println(contV);// imprimimos el valor que adquiere la variable de conteo
    contV=0;// reseteamos la variable de conteo
    } 
      
}
