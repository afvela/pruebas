<?php

// Vector multidimensional con rutas a controlador y método que debe
// atender cada enlace
/* formato:
    Primera dimensaión: nombre del enlace pasado mediante variable GET 'ctl'
     'nombreEnlace' => array() segunda dimesion con información del controlador
                       que atiende esa petición, clave 'controller', y del
                       método concreto que está especializado en su tratamiento,
                       clave 'action'
  Se debe agregar una ruta por cada valor diferente que tome la variable 'ctl'.
  La clave 'inicio' referencia la página home de la aplicación y especifica
    el controlador que debe decidir cuál es la vista que se debe mostrar
*/
$mapeoRutas =
  array('inicio' =>array('controller' =>'defaultController', 'action' =>'inicio'),
        'temas' =>array('controller' =>'temasController', 'action' =>'verTema'),
        'registro' =>array('controller' =>'registroController', 'action' =>'registrarse'),
        'cerrar' =>array('controller' =>'defaultController', 'action' =>'cerrar'),
        'login' =>array('controller' =>'registroController', 'action' =>'login'),
        'miscursos' =>array('controller' =>'defaultController', 'action' =>'miscursos'),
        'unirse' =>array('controller' =>'temasController', 'action' =>'unirseCurso'),
       );