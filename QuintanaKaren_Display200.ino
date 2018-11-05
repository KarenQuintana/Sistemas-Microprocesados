/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA/CIERCOM
 * Nombre:Karen Quintana
 * Fecha:02/11/2018
 * Contar de forma automática (sin pulsador, el sistema inicia y empieza a contar sin necesidad de una 
 * actividad del usuario).Del 1 al 200 mediante la multiplexación de displays.
 */
 int A=5;//plantea una variable de salida para en 7447 en el pin 5 del arduino como entero
 int B=4;//plantea una variable de salida para en 7447 en el pin 4 del arduino como entero
 int C=3;//plantea una variable de salida para en 7447 en el pin 3 del arduino como entero
 int D=2;//plantea una variable de salida para en 7447 en el pin 2 del arduino como entero
 int i =0;//se inicializa la variable de conteo
 int dec=9;// variable de decenas en el pin 9
 int uni=8;//variable unidades en el pin 8
 int cen=10;//variable centenas en el pin 10
 int decenas;// se establece las decenas como variable
 int unidades;// variable unidades
 int centenas;//variable centenas
void setup() {
 
  pinMode(A,OUTPUT);//definir como variale de salida
  pinMode(B,OUTPUT);//definir vaiable de salida
  pinMode(C,OUTPUT);//definir variable de salida
  pinMode(D,OUTPUT);//definir variable de saalida
  pinMode(dec,OUTPUT);//variable de salida al display
  pinMode(uni,OUTPUT);//variable de salida al display
  pinMode(cen,OUTPUT);//variable de salida al display
}

void loop() {
  if(i<200){// si la variable de conteo es menor a 200
    i++;//la variable va incrementando en uno
    centenas=i/100;// se obtiene el valor de las centenas dividiendo la variable de conteo para 100
    decenas=i/10-(centenas*10);//se divide la variable de conteo y resta la parte de centenas *10 debido a que solo tiene dos cifras
    unidades=i-(decenas*10)-(centenas*100);//a la variable de conteo se resta las decenas multilicado por 10 y centenas *100 debido a sus 3 cifras
  }
 else{
 i=0;// una vez terminado se inicializa en 0
 }
  digitalWrite(uni,HIGH);//display de las unidades activadas
  digitalWrite(dec,LOW);//display de las decenas apagadas
  digitalWrite(cen,LOW);//display de las centenas apagadas
 contador (unidades);//se llama la función de contador en función de los parámetros de unidades 
 delay(100);// espero
 digitalWrite(uni,LOW);//display de las unidades apagadas
  digitalWrite(dec,HIGH);//display de las decenas activadas
  digitalWrite(cen,LOW);//display de las centenas apagadas
 contador (decenas);//se llama la función de contador en función de los parámetros de decenas
 delay(100);//espero
  digitalWrite(uni,LOW);//display de las unidades apagadas
  digitalWrite(dec,LOW);//display de las decenas apagadas
  digitalWrite(cen,HIGH);//display de las centenas activadas
 contador (centenas);//se llama la función de contador en función de los parámetros de centenas
 delay(100);
}
void contador (int j){//se establece la función para un contador del 0-9
  switch(j){
    // número 0
  case 0:// número 0
  digitalWrite(A,LOW);//1
 digitalWrite(B,LOW);//2
 digitalWrite(C,LOW);//4
 digitalWrite(D,LOW);//8
break;
// número 1
case 1:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
 // número 2 
 case 2:
digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
// número 3 
case 3:
digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
 // número 4 
 case 4:
digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
// número 5 
case 5:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
break;
 // número 6 
 case 6:
digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
 // número 7 
 case 7:
digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
 // número 8 
 case 8:
digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
break;
 // número 9 
 case 9:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
break;
 }
}
