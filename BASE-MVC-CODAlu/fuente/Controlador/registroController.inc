<?php
// Ejemplo de controlador para página home de la aplicación
class registroController
{ public function registrarse()
{

    if (isset($_POST["ok"])){
        require_once __DIR__ . '/../Repositorio/registroRepositorio.inc';
        try{
           (new registroRepositorio)->registrar($_POST["usuario"],$_POST["contraseña"]);

        }catch(PDOException $ex){
            echo $ex->getMessage();
        }
        $_SESSION["usuario"]=$_POST["usuario"];
        header("location:index.php?ctl=inicio");

    }else{
        require __DIR__ . '/../../app/plantillas/registro.php';
    }

}
    public function login()
    {

        if (isset($_POST["ok"])){
            require_once __DIR__ . '/../Repositorio/registroRepositorio.inc';
            try{
                var_dump(!((new registroRepositorio)->login($_POST["usuario"],$_POST["contraseña"])));
                if(!((new registroRepositorio)->login($_POST["usuario"],$_POST["contraseña"]))){
                    $error="O la contraseña o el usuario no es el correcto";
                    require __DIR__ . '/../../app/plantillas/login.php';
                }else{
                    $_SESSION["usuario"]=$_POST["usuario"];
                    header("location:index.php?ctl=inicio");
                }

            }catch(PDOException $ex){
                echo $ex->getMessage();
            }



        }else{
            require __DIR__ . '/../../app/plantillas/login.php';
        }

    }
}
