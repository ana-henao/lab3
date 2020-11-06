/*
1.Ingrese las combinaciones que correspondan a los 
identificadores de los usuarios. (A, B, C, AA, AB, etc)

2.Ingrese la clave de 4 digitos.
*/


//  **Aplicacion cajero automatico**


//  **Librarias incluidas:  **


#include <LiquidCrystal.h>
#include <Keypad.h>

#define TAM 4
//*************************************************************************
//*************************************************************************

//configuración LCD
LiquidCrystal lcd(13,12,11,10,9,8);

//*************************************************************************
//*************************************************************************
//Configuración teclado matricial
const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {7,6,5,4}; 
byte colPins[cols] = {3,2,1,0}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

// **Variables globales**

char usuarioSudo[4]={'A','B','C','D'};
int opcion=0;
char contrasenaSudo[4]={'1','2','*','4'};
int cont=0;
String usuariosBD[20];
String contrasenaBD[20];
String saldos[20];
int cantu=0;
String ID="";

//  **Funciones**

bool VerifUsuario(bool Sudo);
bool VerifContrasena(bool Sudo);
void Registro_Usuarios();
int GetUser(String user);



//  **Inicio de programa**
void setup() {
  
 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido al");
  lcd.setCursor(0,1);
  lcd.print(" cajero.");
  delay(3000);
  lcd.clear();
  lcd.print("#-enter");
}

void loop() {
  	lcd.clear();
  	lcd.print("menu Ingreso: ");
    lcd.setCursor(0,1);
    delay(400);
    lcd.print("opcion:1.Admin");
    delay(3000);
    lcd.clear();
    lcd.print("2.Usuario");
    delay(2000);
    lcd.clear();
    lcd.print("ingrese opcion:");
  	opcion=keypad.waitForKey()-48;//guarda tecla en variable
  	

  	if(opcion==1){
      		char digito;
            
            lcd.setCursor(0,0);
            lcd.print("ingrese usuario administrador: ");
      		lcd.setCursor(0,1);
      		
      bool usuarioSudo_=VerifUsuario(true);
      
       
      lcd.clear();
      if(usuarioSudo_==true){
      		lcd.setCursor(0,0);
            lcd.print("ingrese contrasena: ");
      		lcd.setCursor(0,1); 
       		
        bool contrasena=VerifContrasena(true);
        
        	if (contrasena==true){
          		lcd.clear();
              	lcd.setCursor(0,0);
            	lcd.print("Acceso valido.");
            	delay(1000);
              	lcd.clear();
              	lcd.print("registro");
              	lcd.setCursor(0,1);
              	lcd.print("usuarios");
              	delay(2000);
              	Registro_Usuarios(); 	
            }
        	else{
              lcd.setCursor(0,0);
              lcd.print("clave");
              lcd.setCursor(0,1);
              lcd.print("incorrecta.");
              delay(1000);
            
            } 
        	
      }
      else{
       	lcd.setCursor(0,0);
        lcd.print("usuario");
      	lcd.setCursor(0,1);
        lcd.print("incorrecto");
        delay(1000);
      }
  }
  else if(opcion==2){
    lcd.clear();
    lcd.setCursor(0,0);
   	lcd.print("ingrese usuario");
    lcd.setCursor(0,1);
      		
    bool usuario_=VerifUsuario(false);
      
    lcd.clear();
    if(usuario_==true){
      lcd.setCursor(0,0);
      lcd.print("ingrese contrasena: ");
      lcd.setCursor(0,1);
      
      bool contrasena_=VerifContrasena(false);
      if(contrasena_==true){
       	lcd.clear();
        lcd.setCursor(0,0);
      	lcd.print("1.Ver saldo");
        lcd.setCursor(0,1);
        lcd.print("2.Retirar");
        int u=keypad.waitForKey()-48;
        if(u==1){
         int p=GetUser(ID);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Saldo:");
         lcd.setCursor(0,1);
         lcd.print(saldos[p]);
         delay(2000);
        }
        else if(u==2){
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("valor retiro:");
         lcd.setCursor(0,1);
          String saldo="";
          for (int j=0; j<10; j++){
              char digito=keypad.waitForKey();
              lcd.print(digito);

              if(digito=='#'){
                  lcd.print("                   ");
                  lcd.setCursor(0,1);
                  break;
              }
              else{
                  saldo+=digito;
              }

           }
          int s=saldo.toInt();
          int p=GetUser(ID);
          int sant=saldos[p].toInt();
          saldos[p]=(String)(sant-s);
        }
        else{
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("opcion");
          lcd.setCursor(0,1);
          lcd.print("incorrecta.");
          delay(1000);
        }
      }
      else{
        lcd.setCursor(0,0);
        lcd.print("Contraseña");
        lcd.setCursor(0,1);
        lcd.print("incorrecta");
        delay(1000);
      }
    }
    else{
      lcd.setCursor(0,0);
      lcd.print("usuario");
      lcd.setCursor(0,1);
      lcd.print("incorrecto");
      delay(1000);
    }
  	
  }
  else{
   	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("opcion");
    lcd.setCursor(0,1);
    lcd.print("incorrecta.");
  	delay(1000);
  }
              
}


//funciones 

bool VerifUsuario(bool Sudo){
  	bool usuarioSudo_=true;
  	ID="";
    for (int j=0; j<4; j++){
         	char digito=keypad.waitForKey();
           	lcd.print(digito);
           	if(digito=='#'){
                	lcd.print("                   ");
                	lcd.setCursor(0,1);
                	break;
 			}
      		else{
      			if (digito!=usuarioSudo[j] && Sudo==true){
              		
              		usuarioSudo_=false;
                	break;
           		}
      				
      			if(Sudo==false){
                  ID+=String(digito);
      					
                }	
            }
            
     }
  if(Sudo==false){
    usuarioSudo_=false;
    for(int i=0; i<sizeof(usuariosBD);i++){
      if(ID==usuariosBD[i]){
       	 usuarioSudo_=true;
        	break;
      }
    }
  }
  return usuarioSudo_;
}

bool VerifContrasena(bool Sudo){
  String ID="";
  bool contrasena=true;
  for (int j=0; j<4; j++){
    char digito=keypad.waitForKey();
    lcd.print("*");
    if(digito=='#'){
 	  	lcd.print("                   ");
        lcd.setCursor(0,1);
         break;
	}
    else{
    	if (digito!=contrasenaSudo[j] && Sudo==true){
         contrasena=false;
         break;
    	}
      	if(Sudo==false){
                  ID+=digito;
      					
                }
    }
    
  }
  if(Sudo==false){
    contrasena=false;
    for(int i=0; i<sizeof(contrasenaBD);i++){
      if(ID==contrasenaBD[i]){
       	 contrasena=true;
        	break;
      }
    }
  }
  return contrasena;
}

  
void Registro_Usuarios(){
	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Ingrese ID: ");
  	lcd.setCursor(0,1);
  	String ID="";
  	for (int j=0; j<4; j++){
    	char digito=keypad.waitForKey();
    	lcd.print(digito);
      	
      	if(digito=='#'){
 	  		lcd.print("                   ");
        	lcd.setCursor(0,1);
         	break;
		}
      	else{
        	ID+=digito;
        }
      	
	}
  	usuariosBD[cantu]=ID;
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Ingrese clave: ");
  	lcd.setCursor(0,1);
  	String clave="";
  	for (int j=0; j<4; j++){
    	char digito=keypad.waitForKey();
    	lcd.print(digito);
    	
		if(digito=='#'){
 	  		lcd.print("                   ");
        	lcd.setCursor(0,1);
         	break;
		}
      	else{
        	clave+=digito;
        }
    }
  	
  	contrasenaBD[cantu]=clave;
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Ingrese saldo: ");
  	lcd.setCursor(0,1);
  	String saldo="";
  	for (int j=0; j<10; j++){
    	char digito=keypad.waitForKey();
    	lcd.print(digito);
      	
    	if(digito=='#'){
 	  		lcd.print("                   ");
        	lcd.setCursor(0,1);
         	break;
		}
      	else{
        	saldo+=digito;
        }
    
	}
  	saldos[cantu]=saldo;  
  	cantu++;
}

int GetUser(String user){
	int pos=-1;
  	for(int i=0; i<sizeof(usuariosBD);i++){
      
      if(user==usuariosBD[i]){
       	 pos=i;
         break;
      }
    }
  	return pos;
  
}
