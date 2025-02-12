/*
 * Nombre del archivo: pluviometer.h
 * Descripción: Biblioteca para la detección y reporte de lluvias usando un pluviómetro.
 * Autor: Luis Gómez P.
 * Derechos de Autor: (C) 2023 Luis Gómez P.
 * Licencia: GNU General Public License v3.0
 * 
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 * 
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita
 * de COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO PARTICULAR. Ver la
 * Licencia Pública General GNU para más detalles.
 * 
 * Deberías haber recibido una copia de la Licencia Pública General GNU
 * junto con este programa. Si no es así, visita <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

#ifndef PLUVIOMETER_H
#define PLUVIOMETER_H

/** @file
 ** @brief Biblioteca para la detección y reporte de lluvias usando un pluviómetro.
 **/

/* === Headers files inclusions ================================================================ */

#include "mbed.h"
#include "debounce.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

// Constantes de configuración
#define TIME_INI  1593561600  ///< 1 de julio de 2020, 00:00:00
#define BAUD_RATE 9600  ///< Velocidad de comunicación serial
#define DELAY_BETWEEN_TICK 500  ///< 500 ms
#define SWITCH_TICK_RAIN BUTTON1  ///< Botón para detectar lluvia

#define MM_PER_TICK 2  ///< 2 décimas de mm de agua por tick
#define RAINFALL_COUNT_INI 0  ///< Contador de lluvia inicial
#define LAST_MINUTE_INI -1  ///< Último minuto inicial
#define DEBOUNCE_TIME 80 ///< tiempo del antirrebote

// Mensajes y formatos
#define MSG_RAIN_DETECTED " - Rain detected\r\n"  ///< Mensaje de lluvia detectada
#define MSG_ACCUMULATED_RAINFALL " - Accumulated rainfall: "  ///< Mensaje de lluvia acumulada
#define TIME_FORMAT "%Y-%m-%d %H:%M:%S"  ///< Formato de tiempo completo
#define DATE_FORMAT "%Y-%m-%d %H:%M"  ///< Formato de fecha y hora


/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */
void initializeDebounce();
void updateDebounce();

extern DigitalOut alarmLed;  ///< LED de alarma
extern DigitalOut tickLed;  ///< LED de tick

// Variables globales
extern BufferedSerial pc;  ///< Comunicación serial

/* === Public function declarations ============================================================ */

// Sensores
void initializeSensors();
bool isRaining();
bool hasTimePassedMinutesRTC(int minutes);

// Actuación
void actOnRainfall();
void reportRainfall();

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* PLUVIOMETER_H */
