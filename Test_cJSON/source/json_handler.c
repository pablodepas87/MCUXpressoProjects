#include <stdio.h> 
#include "cJSON.h"
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"

char* createJson() {
    char  *json_string = NULL;
    cJSON *studente = cJSON_CreateObject();
    cJSON *nomeStudente =NULL;
    
    nomeStudente = cJSON_CreateString("Fabio");
    /* Esempio usando cJSON_AddItemToObject che vuolr in ingresso l'oggetto , nome della chiave e l'elemento CJSON */
    cJSON_AddItemToObject(studente,"nome",nomeStudente); 
    /* ora utilizzo cJSON_AddStringToObject che prende in ingresso oggetto, , stringa key , stringa valore */
    cJSON_AddStringToObject(studente,"cognome","Rapicano");
    /* ora aggiungo l'età che è un numero con cJSON_AddNumberToObject */
    cJSON_AddNumberToObject(studente,"età",33) ;

    return json_string = cJSON_Print(studente);

}

void parseJson( const char *json_string){
   cJSON *nome_studente = NULL;
   cJSON *cognome_studente = NULL;
   cJSON *eta_studente = NULL;
   const char *err_json = NULL;

   cJSON *all_Json = cJSON_Parse(json_string);          // faccio il parse della stringa letta ottenuta dalla lettura del file

   if ( all_Json == NULL ) {
        err_json = cJSON_GetErrorPtr();
        printf("Error before: %s\n", err_json);
   }

   // inizio l'analisi dei vari campi
   nome_studente = cJSON_GetObjectItemCaseSensitive(all_Json,"nome");
   if(cJSON_IsString(nome_studente) && (nome_studente->valuestring != NULL)){
       printf("\nnome studente:%s\n",nome_studente->valuestring);
   }
   cognome_studente = cJSON_GetObjectItemCaseSensitive(all_Json,"cognome");
   if(cJSON_IsString(cognome_studente) && (cognome_studente->valuestring)){
        printf("cognome studente:%s\n",cognome_studente->valuestring);
   }
   eta_studente = cJSON_GetObjectItemCaseSensitive(all_Json,"età");
   if(cJSON_IsNumber(eta_studente)){
       printf("eta' studente:%d\n\n",eta_studente->valueint);
   }

}
