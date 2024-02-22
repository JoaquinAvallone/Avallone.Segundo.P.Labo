#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED


/// @brief Confirma o rechaza la salida del programa
///
/// @param pRespuesta Parametro el cual cargar con la respuesta del usuario
/// @param confirma si el usuario ingresa s confima la salida
/// @param rechaza si el usuario ingresa n rechaza la salida
/// @return Retorna 1 si la direccion de memoria es distinta de NULL
int confirmaSalida(char* pRespuesta, char confirma, char rechaza);

/// @brief Valida el ingreso de un numero sin permitir letras
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo  Es el minimo maximo a ser aceptado
/// @param reintentos cantidad de reintentos permitidos
/// @return  Retorna 1 si se obtuvo el numero y -1 si no
int utn_getNumeroInt (int* pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

/// @brief  Verifica si la cadena ingresada es numerica
/// @param pResultado  Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return  Retorna 1 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int getInt(int* pResultado);

/// @brief Verifica si la cadena ingresada es numerica
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
int esNumericaInt ( char * cadena);

/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena* un máximo de 'longitud - 1' caracteres.
///
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud  Define el tamaño de cadena
/// @return Retorna 1 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
int myGets ( char * cadena, int longitud);

/// @brief Valida el ingreso de un numero sin permitir letras
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError  Es el mensaje de Error a ser mostrado
/// @param minimo Es el minimo minimo a ser aceptado
/// @param maximo  Es el numero maximo a ser aceptado
/// @param reintentos  cantidad de reintentos permitidos
/// @return Retorna 1 si se obtuvo el numero y -1 si no
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

/// @brief Verifica si la cadena ingresada es numerica
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
int esNumericaFloat ( char * cadena);

/// @brief Verifica si la cadena ingresada es numerica
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 1 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int getFloat ( float * pResultado);

/// @brief Verifica si la cadena ingresada son caracteres
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos cantidad de reintentos permitidos
/// @return Retorna 1 si se obtuvo la cadena de caracteres  y -1 si no
int utn_getString ( char * pResultado, char * mensaje, char * mensajeError, int reintentos);

/// @brief Verifica si la cadena ingresada son caracteres
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 1 si se obtuvo la cadena de caracteres  y -1 si no
int getChar ( char * pResultado);

/// @brief Verifica si la cadena ingresada son caracteres
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 si se obtuvo la cadena de caracteres  y -1 si no
int esNumericaChar ( char * cadena);

/// @brief Verifica que lo ingresado sea s o n
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje  Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos cantidad de reintentos permitidos
/// @return retorna 1 si se pude o retorna -1 si no se pudo
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos);
