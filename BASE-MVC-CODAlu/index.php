<?php
//index.php
session_start();
error_reporting(E_ALL);


require_once __DIR__ . '/fuente/Controlador/temasController.inc';
require_once __DIR__ . '/fuente/Controlador/registroController.inc';
require_once __DIR__ . '/fuente/Controlador/defaultController.inc'; /*controladores */
require_once __DIR__ . '/app/conf/rutas.inc'; /*Ubicación del archivo de rutas*/


// Parseo de la ruta
if (isset($_GET['ctl']))
{ if (isset($mapeoRutas[$_GET['ctl']]))
  { $ruta = $_GET['ctl'];
      $param = isset($_GET['act'])?unserialize(urldecode(stripslashes($_GET['act']))): '';//equivale a isset $_GET
  }else
  { header('Status: 404 Not Found');
    echo '<html><body><h1>Error 404: No existe la ruta <i>' .
          $_GET['ctl'] .
          '</p></body></html>';
    exit;
  }
}else
{ $ruta = 'inicio';
}

$controlador = $mapeoRutas[$ruta];
// Ejecución del controlador asociado a la ruta

if (method_exists($controlador['controller'],$controlador['action']))
{
    if (empty($param)) {
    call_user_func(array(new $controlador['controller'], $controlador['action']));
}else{
    call_user_func(array(new $controlador['controller'], $controlador['action']), $param);
}
}else
{ header('Status: 404 Not Found');
  echo '<html><body><h1>Error 404: El controlador <i>' .
       $controlador['controller'] .
       '->' . $controlador['action'] .
       '</i> no existe</h1></body></html>';
}
