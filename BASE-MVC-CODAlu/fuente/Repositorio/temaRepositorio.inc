<?php

class temaRepositorio
{
    function getTemas($curso): array
    {

        $sql = 'SELECT idTema , numTema, nombre, objetivos FROM temas WHERE idCurso= :idCurso';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':idCurso', $curso[1]);
            $snt->execute();
            return $snt->fetchAll(PDO::FETCH_ASSOC);
        } catch (PDOException $ex) {
            throw $ex;
        } finally {
            $snt = null;
            $con = null;
        }
    }


    function unirseCurso($curso)
    {
        $fmatri = date('d-m-Y');
//        print_r($curso);
//        die(print_r($_SESSION));
        $sql2 = 'select e.idEstudiante as estudiante from usuario as u join estudiante e on e.idUsuario=u.idUsuario where u.usu=:usu;';

        $sql = 'insert into Matricula values (:idCurso,:idestudiante,:fmatri,:fini,:ffin);';

        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {


            $con = (new ConexionBd())->getConexion();
            //$con->beginTransaction();

            $snt2 = $con->prepare($sql2);
            $snt2->bindValue(':usu', $_SESSION['usuario']);
            $snt2->execute();
            $estudiante = $snt2->fetch(PDO::FETCH_ASSOC)["estudiante"];
            $snt = $con->prepare($sql);
            $snt->bindValue(':idCurso', $curso[1]);
            $snt->bindValue(':fmatri', $fmatri);
            $snt->bindValue(':fini', $fmatri);
            $snt->bindValue(':idestudiante', $estudiante);
            $snt->bindValue(':ffin', date('d-m-Y', strtotime(date('d-m-Y') . "+6 month")));
            $snt->execute();

        } catch (PDOException $ex) {
            throw $ex;
        } finally {
            $snt = null;
            $con = null;
        }
    }
}