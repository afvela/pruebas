<?php


class cursoRepositorio
{
    public function getCursos():array{
        $sql='SELECT idCurso AS idCurs, nombre, horas, descripcion FROM curso';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try{
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->execute();
            return $snt->fetchAll(PDO::FETCH_ASSOC);
        }catch(PDOException $ex){
            throw $ex;
        }finally{
            $snt = null;
            $con = null;
        }
    }
    public function getCursosUsu($usuario):array{
        $sql='SELECT c.idCurso AS idCurs, c.nombre, c.horas, c.descripcion FROM curso as c join Matricula as m on
 c.idCurso=m.idCurso join Estudiante as e on e.idEstudiante=m.idEstudiante join Usuario as u on u.idUsuario=e.idUsuario where u.usu=:usu;';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try{
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':usu', $usuario);
            $snt->execute();
            return $snt->fetchAll(PDO::FETCH_ASSOC);
        }catch(PDOException $ex){
            throw $ex;
        }finally{
            $snt = null;
            $con = null;
        }
    }
    public function getCursosUsuNot($usuario):array{
        $sql='select c.idCurso AS idCurs, c.nombre, c.horas, c.descripcion from Curso as c
 except
 SELECT c.idCurso AS idCurs, c.nombre, c.horas, c.descripcion FROM curso as c join Matricula as m on
 c.idCurso=m.idCurso join Estudiante as e on e.idEstudiante=m.idEstudiante join Usuario as u on u.idUsuario=e.idUsuario where u.usu=:usu;';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try{
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':usu', $usuario);
            $snt->execute();
            return $snt->fetchAll(PDO::FETCH_ASSOC);
        }catch(PDOException $ex){
            throw $ex;
        }finally{
            $snt = null;
            $con = null;
        }
    }
}