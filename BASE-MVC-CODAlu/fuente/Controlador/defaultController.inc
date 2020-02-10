<?php
// Ejemplo de controlador para página home de la aplicación
class DefaultController
{ public function inicio()
  {
      require_once __DIR__ . '/../Repositorio/cursoRepositorio.inc';
      if(isset($_SESSION["usuario"])){
          $cursos=(new cursoRepositorio)->getCursosUsuNot($_SESSION["usuario"]);
      }else{
          $cursos=(new cursoRepositorio)->getCursos();
      }
    require __DIR__ . '/../../app/plantillas/inicio.php';
  }
    public function cerrar()
    {
        require_once __DIR__ . '/../Repositorio/cursoRepositorio.inc';
        session_destroy();
        $cursos=(new cursoRepositorio)->getCursos();
        header("location:index.php?ctl=inicio");
    }
    public function miscursos()
    {
        require_once __DIR__ . '/../Repositorio/cursoRepositorio.inc';
        if(isset($_SESSION["usuario"])){
            $cursos=(new cursoRepositorio)->getCursosUsu($_SESSION["usuario"]);
        }else{
            $cursos=(new cursoRepositorio)->getCursos();
        }
        require __DIR__ . '/../../app/plantillas/miscursos.php';
    }
}
