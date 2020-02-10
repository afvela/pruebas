<?php

class temasController
{
    public function verTema(array $curso)
    {
        require_once __DIR__ . '/../Repositorio/temaRepositorio.inc';
        $temas = (new temaRepositorio)->getTemas($curso);
        include_once __DIR__ . '/../../app/plantillas/verTemas.php';
    }
    public function unirseCurso(array $curso)
        {
            require_once __DIR__ . '/../Repositorio/temaRepositorio.inc';
            (new temaRepositorio)->unirseCurso($curso);
            $temas = (new temaRepositorio)->getTemas($curso);
            include_once __DIR__ . '/../../app/plantillas/verTemas.php';
        }
}

