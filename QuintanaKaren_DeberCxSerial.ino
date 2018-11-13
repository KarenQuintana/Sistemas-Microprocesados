
/* 
 *  UNIVERSIDAD TÉCNICA DEL NORTE
 *  Nombre: Karen Quintana
 *  Fecha: 13/11/2018
 *  TEMA: DEBER CX SERIAL 
 * Estimados estudiantes como lo dialogamos en clase. Realizar un programa que permita ingresar 
 * el número de cédula con el guión y posteriormente validarlo. El dato se lo ingresa por 
 * comunicación serial. 
 */

 //Validación de la cédula:
 String cedula;// Dato que se recibe por serial
 int tamC=0;//Variable para determinar el tamaño de Cedula
 int i=0;// Variable de conteo o recorrido
 char dato;//Variable de
 int ent;// variable para dig enteros
 int pm=0; //Variable que permite verificar el funcionamiento adecuado del modulo 10
 int dec=0; //Variable para obtener las decenas del modulo
 int decM=0;//Variable para obtener decena superior al mod
 
 void setup() {
  Serial.begin(9600);//habilitar comunicación serial
  Serial.println("Ingrese la cédula que desea validar");//Solicitar Dato una vez para todo el programa
}

void loop() {
  if(Serial.available()>0){// mientras exista el dato para procesar 
    cedula=Serial.readString();//Lee palabra ingresada
    tamC=cedula.length();//conocer tamaño del string
    char vectorC[tamC];//declara el vector de tamaño
    cedula.toCharArray(vectorC,tamC+1);//convertir se crea vector tipo char
    if(tamC==11){// condiciona que deben existir 11 carácteres
      if (vectorC[9]=='-'){// Verifica la posición 9 del vector que presente un guión
        for (; i < 9; i++) { // evalua el vector dato por dato
        dato = vectorC[i];//
           if (isDigit(dato)) {// Comprobar si todos son números
           if(vectorC[2]=='0'||vectorC[2]=='1'||vectorC[2]=='2'||vectorC[2]=='3'||vectorC[2]=='4'||vectorC[2]=='5'){// Validar que el tercer dígito no puede ser mayor a 6
           if(vectorC[0]=='0'||vectorC[0]=='1'||vectorC[0]=='2'){// validar que el primer digito no puede ser mayor a 2
           if(vectorC[1]=='0'||vectorC[1]=='1'||vectorC[1]=='2'||vectorC[1]=='3'||vectorC[1]=='4'){// validar que el segundo digito no puede ser mayor a a
          //Validación último digito
           if (i % 2 == 0) { //se establece para números pares condición de modulo
            if (ent*2>10) { //si el resultado de la multiplicación es mayor a 10
              pm = pm+ent*2-9; //se le resta nueve cuando se le multiplica por su coeficiente de multiplicación{1,2,1...}
            } else { //si el resultado de la multiplicación e  menor a 9
              pm = pm+2*ent; //se mantiene igual
            }
            }else { //si los digitos son pares su modulo 10 es
            pm = pm + ent; //Sumatoria total
          }
           
           }
            else {
            Serial.println("La cedula ingresada es incorrecta,2 digitos primeros"); 
            break;
           }
           }
           else {
            Serial.println("La cedula ingresada es incorrecta,2 digitos primeros"); 
             break;
           }
            
          }else{
            Serial.println("La cedula ingresada es incorrecta,3 digito debe ser mayor a 6");
             break; 
          }
          
          }else{
         Serial.println("La cedula ingresada es incorrecta, deben ser números"); 
          break;
        }
        }
        i=0;
        if (tamC==11) { //Si cumple
          dec=pm/10; //división para obtener decenas sumatoria total
          decM=(dec+1)*10-pm; //Se resta la decena superior
         dato= vectorC [10]; //se agrega el digito 10
          if (decM==atoi(&dato)) { //cumple modulo 10
            Serial.println("Cedula ingresada correctamente"); 
          } else {
            Serial.println("La cedula ingresada es incorrecta,ultimo digito invalido"); 
          }
        } 
        }
        else{
        Serial.println("La cedula ingresada es incorrecta, debe tener guion");
      }
    }else{
      Serial.println("La cedula ingresada es incorrecta, no tiene 11 carácteres");
    }
}else{
  Serial.println("No a ingresado cedula a validar");
  }
}
