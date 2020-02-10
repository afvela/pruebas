<?php
$cliente = new SoapClient(null, ['location' => 'http://Biblioteca2.edu/servicioWeb/servicio.php',
                                        'uri' => 'urn:Biblioteca2.edu/serviciosWeb/servicio.php',
                                        'trace' => 1]);
try {
    $libro = $cliente->getLibro(rand(1, 21));
} catch (PDOException $ex) {
    echo ($cliente->__getLastResponse());
    echo PHP_EOL;
    echo ($cliente->__getLastRequest());
}
?>
<!DOCTYPE html>
<html>
<head>
    <style media="screen">
        table{
            width: 80%;
            margin: auto;
        }
        th{
            text-align: right;
            vertical-align: top;
            font-family: cursive;
        }
        td{
            font-family: Verdana;
        }
    </style>
</head>
<body>

<table>
    <?php
    if(!empty($libro)):?>
    <?php foreach($libro as $key => $value):?>

        <tr>
            <th><?= $key ?></th>
            <td><?= $value ?></td>
        </tr>
    <?php endforeach; ?>

</table>

<?php else: ?>
    <p>no hay ningun libro con ese identificador</p>
<?php endif; ?>

</body>
</html>
