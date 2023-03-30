<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>q14</title>
    <style>
        div{
            font-family: monospace;
            font-size: 2em;
            color: blueviolet;
            text-align: center;
        }
    </style>
</head>

<body>
    <div>
        <?php
        $string = "This is a test string. PLEASE HAVE FUN";
        echo strtoupper($string) . "<br>";
        echo strtolower($string) . "<br>";
        echo ucfirst($string) . "<br>";
        echo ucwords($string) . "<br>";
        ?>
    </div>
</body>

</html>