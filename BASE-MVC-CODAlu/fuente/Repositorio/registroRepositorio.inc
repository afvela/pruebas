<?php


class registroRepositorio
{
    public function registrar($usuario, $contrasena)
    {
        $sql = 'insert into Usuario values (:usuario,:pwd);';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':usuario', $usuario);
            $snt->bindValue(':pwd', $contrasena);
            $snt->execute();
        } catch (PDOException $ex) {
            throw $ex;
        } finally {
            $snt = null;
            $con = null;
        }
    }
    public function login($usuario, $contrasena)
    {
        $sql = 'SELECT * FROM Usuario WHERE usu = :usuario AND pwd = :pwd;';
        //
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':usuario', $usuario);
            $snt->bindValue(':pwd', $contrasena);
            $snt->execute();
            $cuenta = $snt->rowCount();
            if($cuenta==0){
                return false;
            }else{
                return true;
            }
        } catch (PDOException $ex) {
            throw $ex;
        } finally {
            $snt = null;
            $con = null;
        }
        return false;
    }
}