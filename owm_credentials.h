//################  IOTWEBCONF  ##################################################

#include <IotWebConf.h>
#include <IotWebConfUsing.h> // This loads aliases for easier class names.
#include <IotWebConfTParameter.h>

// -- Configuration specific key. The value should be modified if config structure was changed.
#define CONFIG_VERSION "1.7"


const bool DebugDisplayUpdate = false;

// Data needed to access Ambient Weather API
// IotWebConfParameterGroup ambGroup = IotWebConfParameterGroup("ambGroup", "Ambient API Data");

// const int ambientApiEndpoint_LEN                            =  51;
// iotwebconf::TextTParameter<ambientApiEndpoint_LEN> ambientApiEndpointParam =
//   iotwebconf::Builder<iotwebconf::TextTParameter<ambientApiEndpoint_LEN>>("ambientApiEndpoint").
//   label("Ambient API Endpoint").
//   defaultValue("api.ambientweather.net").
//   build();

// const int ambientApiKey_LEN                              =  65;
// iotwebconf::TextTParameter<ambientApiKey_LEN> ambientApiKeyParam =
//   iotwebconf::Builder<iotwebconf::TextTParameter<ambientApiKey_LEN>>("ambientApiKey").
//   label("Ambient API Key").
//   defaultValue("e111635001b140059ec8e329d0981dbf39c0e2fddbe9430f990c73355b8363e1").
//   build();

// const int ambientApplicationKey_LEN                      =  65;
// iotwebconf::TextTParameter<ambientApplicationKey_LEN> ambientAppKeyParam =
//   iotwebconf::Builder<iotwebconf::TextTParameter<ambientApplicationKey_LEN>>("ambientApplicationKey").
//   label("Ambient Application Key").
//   defaultValue("b4bebeed184a4c7b97fe9326995f4781e68d73e501854b6287351d0079c4122f").
//   build();

// const int ambientDeviceMac_LEN                           =  18;
// iotwebconf::TextTParameter<ambientDeviceMac_LEN> ambientDeviceMacParam =
//   iotwebconf::Builder<iotwebconf::TextTParameter<ambientDeviceMac_LEN>>("ambientDeviceMAC").
//   label("Ambient Device MAC").
//   defaultValue("DC:4F:22:5A:C1:36").
//   build();

//Settings for the OWM data which provides the forecast and current conditions - pick a city near your station.
// Use your own API key by signing up for a free developer account at https://openweathermap.org/
//String owmApiKey           = "c7b325c7c09d111c29c2ac8fdc6c3c58";                      // See: https://openweathermap.org/
//const char owmWxServer[]   = "api.openweathermap.org";

IotWebConfParameterGroup owmGroup = IotWebConfParameterGroup("owmGroup", "OWM API Data");

const int owmApiKey_LEN                              =  33;
iotwebconf::TextTParameter<owmApiKey_LEN> owmApiKeyParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<owmApiKey_LEN>>("owmApiKey").
  label("OWM API Key").
  defaultValue("c7b325c7c09d111c29c2ac8fdc6c3c58"). //leave this off to make them get their own.
  build();


const int owmWxServer_LEN                            =  50;
iotwebconf::TextTParameter<owmWxServer_LEN> owmWxServerParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<owmWxServer_LEN>>("owmWxServer").
  label("OWM Wx Server").
  defaultValue("api.openweathermap.org").
  build();

//http://api.openweathermap.org/data/2.5/forecast?q=Melksham,UK&APPID=your_OWM_API_key&mode=json&units=metric&cnt=40
//http://api.openweathermap.org/data/2.5/weather?q=Melksham,UK&APPID=your_OWM_API_key&mode=json&units=metric&cnt=1

//Set your location according to OWM locations
//String owmCityName             = "Parker Landing";               // Your home city See: http://bulk.openweathermap.org/sample/
const int owmCityName_LEN                              =  51;
iotwebconf::TextTParameter<owmCityName_LEN> owmCityNameParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<owmCityName_LEN>>("owmCityName").
  label("OWM City").
  defaultValue("Parker Landing").
  build();



// Your _ISO-3166-1_two-letter_country_code country code, on OWM find your nearest city and the country code is displayed
// https://en.wikipedia.org/wiki/List_of_ISO_3166_country_codes
const int owmCountry2Letter_LEN                              =  3;
iotwebconf::TextTParameter<owmCountry2Letter_LEN> owmCountry2LetterParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<owmCountry2Letter_LEN>>("owmCountry2Letter").
  label("OWM Country (2)").
  defaultValue("CA").
  build();

// NOTE: Only the weather description is translated by OWM
// Examples: Arabic (AR) Czech (CZ) English (EN) Greek (EL) Persian(Farsi) (FA) Galician (GL) Hungarian (HU) Japanese (JA)
// Korean (KR) Latvian (LA) Lithuanian (LT) Macedonian (MK) Slovak (SK) Slovenian (SL) Vietnamese (VI)
const int owmLanguage_LEN                              =  3;
iotwebconf::TextTParameter<owmLanguage_LEN> owmLanguageParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<owmLanguage_LEN>>("owmLanguage").
  label("OWM Language (2)").
  defaultValue("EN").
  build();

const int owmHemisphereValue_LEN = 6;
const int owmHemisphereName_LEN = 9;
static const char owmHemisphereValues[][owmHemisphereValue_LEN] = { "north", "south" };
static const char owmHemisphereNames[][owmHemisphereName_LEN] = { "Northern", "Southern"};
iotwebconf::SelectTParameter<owmHemisphereValue_LEN> owmHemisphereParam =
   iotwebconf::Builder<iotwebconf::SelectTParameter<owmHemisphereValue_LEN>>("owmHemisphere").
   label("Choose Hemisphere").
   optionValues((const char*)owmHemisphereValues).
   optionNames((const char*)owmHemisphereNames).
   optionCount(sizeof(owmHemisphereValues) / owmHemisphereValue_LEN).
   nameLength(owmHemisphereName_LEN).
   defaultValue("north").
   build();

const int owmUnitsValue_LEN = 2;
const int owmUnitsName_LEN = 9;
static const char owmUnitsValues[][owmUnitsValue_LEN] = { "I", "M" };
static const char owmUnitsNames[][owmUnitsName_LEN] = { "Imperial", "Metric"};
iotwebconf::SelectTParameter<owmUnitsValue_LEN> owmUnitsParam =
   iotwebconf::Builder<iotwebconf::SelectTParameter<owmUnitsValue_LEN>>("owmHemisphere").
   label("Choose Units").
   optionValues((const char*)owmUnitsValues).
   optionNames((const char*)owmUnitsNames).
   optionCount(sizeof(owmUnitsValues) / owmUnitsValue_LEN).
   nameLength(owmUnitsName_LEN).
   defaultValue("I").
   build();

IotWebConfParameterGroup timeGroup = IotWebConfParameterGroup("timeGroup", "Time and Zone");

// Choose your time zone from: https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv 
// Example time zones
//const char* Timezone = "MET-1METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "CET-1CEST,M3.5.0,M10.5.0/3";       // Central Europe
//const char* Timezone = "EST-2METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "EST5EDT,M3.2.0,M11.1.0";           // EST USA  
//const char* Timezone = "CST6CDT,M3.2.0,M11.1.0";           // CST USA
//const char* Timezone = "MST7MDT,M4.1.0,M10.5.0";           // MST USA
//const char* Timezone = "NZST-12NZDT,M9.5.0,M4.1.0/3";      // Auckland
//const char* Timezone = "EET-2EEST,M3.5.5/0,M10.5.5/0";     // Asia
//const char* Timezone = "ACST-9:30ACDT,M10.1.0,M4.1.0/3":   // Australia
const int timeTimezone_LEN                              =  31;
iotwebconf::TextTParameter<timeTimezone_LEN> timeTimezoneParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<timeTimezone_LEN>>("timeTimezone").
  label("Timezone").
  defaultValue("EST5EDT,M3.2.0,M11.1.0").
  build();

// Or, choose a time server close to you, but in most cases it's best to use pool.ntp.org to find an NTP server
// then the NTP system decides e.g. 0.pool.ntp.org, 1.pool.ntp.org as the NTP syem tries to find  the closest available servers
// EU "0.europe.pool.ntp.org"
// US "0.north-america.pool.ntp.org"
// See: https://www.ntppool.org/en/                                                           
const int ntpServer_LEN                              =  51;
iotwebconf::TextTParameter<ntpServer_LEN> ntpServerParam =
  iotwebconf::Builder<iotwebconf::TextTParameter<ntpServer_LEN>>("ntpServer").
  label("ntp Server").
  defaultValue("0.north-america.pool.ntp.org").
  build();


// UK normal time is GMT, so GMT Offset is 0, for US (-5Hrs) is typically -18000, AU is typically (+8hrs) 28800
iotwebconf::IntTParameter<int32_t> gmtOffsetParam =
  iotwebconf::Builder<iotwebconf::IntTParameter<int32_t>>("gmtOffset").
  label("gmt Offset (secs)").
  min(-43200).
  max(43200).
  step(1).
  defaultValue(-18000).
  placeholder("-18000").
  build();

// In the UK DST is +1hr or 3600-secs, other countries may use 2hrs 7200 or 30-mins 1800 or 5.5hrs 19800 Ahead of GMT use + offset behind - offset
iotwebconf::IntTParameter<int16_t> daylightOffsetParam =
  iotwebconf::Builder<iotwebconf::IntTParameter<int16_t>>("daylightOffset").
  label("daylight offset (secs)").
  min(-7200).
  max(7200).
  step(1).
  defaultValue(3600).
  placeholder("3600").
  build();


// const char* root_ca= \
// "-----BEGIN CERTIFICATE-----\n" \
// "MIIDxTCCAq2gAwIBAgIQAqxcJmoLQJuPC3nyrkYldzANBgkqhkiG9w0BAQUFADBs\n" \
// "MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n" \
// "d3cuZGlnaWNlcnQuY29tMSswKQYDVQQDEyJEaWdpQ2VydCBIaWdoIEFzc3VyYW5j\n" \
// "ZSBFViBSb290IENBMB4XDTA2MTExMDAwMDAwMFoXDTMxMTExMDAwMDAwMFowbDEL\n" \
// "MAkGA1UEBhMCVVMxFTATBgNVBAoTDERpZ2lDZXJ0IEluYzEZMBcGA1UECxMQd3d3\n" \
// "LmRpZ2ljZXJ0LmNvbTErMCkGA1UEAxMiRGlnaUNlcnQgSGlnaCBBc3N1cmFuY2Ug\n" \
// "RVYgUm9vdCBDQTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMbM5XPm\n" \
// "+9S75S0tMqbf5YE/yc0lSbZxKsPVlDRnogocsF9ppkCxxLeyj9CYpKlBWTrT3JTW\n" \
// "PNt0OKRKzE0lgvdKpVMSOO7zSW1xkX5jtqumX8OkhPhPYlG++MXs2ziS4wblCJEM\n" \
// "xChBVfvLWokVfnHoNb9Ncgk9vjo4UFt3MRuNs8ckRZqnrG0AFFoEt7oT61EKmEFB\n" \
// "Ik5lYYeBQVCmeVyJ3hlKV9Uu5l0cUyx+mM0aBhakaHPQNAQTXKFx01p8VdteZOE3\n" \
// "hzBWBOURtCmAEvF5OYiiAhF8J2a3iLd48soKqDirCmTCv2ZdlYTBoSUeh10aUAsg\n" \
// "EsxBu24LUTi4S8sCAwEAAaNjMGEwDgYDVR0PAQH/BAQDAgGGMA8GA1UdEwEB/wQF\n" \
// "MAMBAf8wHQYDVR0OBBYEFLE+w2kD+L9HAdSYJhoIAu9jZCvDMB8GA1UdIwQYMBaA\n" \
// "FLE+w2kD+L9HAdSYJhoIAu9jZCvDMA0GCSqGSIb3DQEBBQUAA4IBAQAcGgaX3Nec\n" \
// "nzyIZgYIVyHbIUf4KmeqvxgydkAQV8GK83rZEWWONfqe/EW1ntlMMUu4kehDLI6z\n" \
// "eM7b41N5cdblIZQB2lWHmiRk9opmzN6cN82oNLFpmyPInngiK3BD41VHMWEZ71jF\n" \
// "hS9OMPagMRYjyOfiZRYzy78aG6A9+MpeizGLYAiJLQwGXFK3xPkKmNEVX58Svnw2\n" \
// "Yzi9RKR/5CYrCsSXaQ3pjOLAEFe4yHYSkVXySGnYvCoCWw9E1CAx2/S6cCZdkGCe\n" \
// "vEsXCS+0yx5DaMkHJ8HSXPfqIbloEpw8nL+e/IBcm2PN7EeqJSdnoDfzAIJ9VNep\n" \
// "+OkuE6N36B9K\n" \
// "-----END CERTIFICATE-----";