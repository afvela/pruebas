<?php
// Ejemplo de controlador para página home de la aplicación
class cursoController
{
    public function verCursos()
    {
        require_once __DIR__ . '/../Repositorio/cursoRepositorio.inc';
        if(isset($_SESSION["usuario"])){
            $cursos=(new cursoRepositorio)->getCursos($_SESSION["usuario"]);
        }else{
            $cursos=(new cursoRepositorio)->getCursos();
        }
        include_once __DIR__ . '/../../app/plantillas/inicio.php';
    }

}
