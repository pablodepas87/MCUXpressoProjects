# Appunti Impostazioni progetto

Per aggiungere la dir che contiene la libreria cJSON ovvero cJSON va impostato il suo path in 2 punti procedendo come segue :

doppio click sul nome del progetto --> Properties --> C/C++ Build --> Settings --> MCU assembler --> General 

aggiungere il path : `"${workspace_loc:/${ProjName}/cJSON}"`

### Settings per evitare errore su __isnan __isinf utilizzate da cJSON

doppio click nome del progetto --> Properties --> C/C++ Build --> Settings --> MCU assembler --> Architecture& Headers

* impostare il campo Library headers a NewLibNano(Auto)

doppio click nome del progetto --> Properties --> C/C++ Build --> Settings --> MCU compiler --> Miscellaneous

* impostare il campo Library headers a NewLibNano(Auto) 
* spuntare l'opzione Generate Stack Usage Info (-fstackusage)

doppio click nome del progetto --> Properties --> C/C++ Build --> Settings --> MCU compiler --> Miscellaneous

* impostare il campo Library headers a NewLibNano(Auto) 
* spuntare l'opzione Generate Stack Usage Info (-fstackusage)

doppio click nome del progetto --> Properties --> C/C++ Build --> Settings --> MCU compiler --> Managed Linker Script

* impostare il campo library NewLibNano(SemiHost) 

* spuntare le opzioni enable printf float e scanfloat (altrimenti non viene salvato il campo numero nel json)

  

