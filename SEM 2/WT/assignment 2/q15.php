<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>q15</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            background-color: aliceblue;
        }

        .arr {
            background-color: beige;
            padding: 10px;
            width: 80vw;
            margin: 20px auto;
            border-radius: 10px;
        }

        .arr h1 {
            font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;
            margin: 0;
        }

        .arr p {
            font-family: monospace;
            padding: 10px;
            margin-left: 40px;
            background-color: #dfdfdf;
            border-radius: 10px;
        }
    </style>
</head>

<body>
    <div class="arr">
        <h1>Unsorted Array</h1>
        <?php
        $arr = array("Sophia" => "31", "Jacob" => "41", "William" => "39", "Ramesh" => "40");
        echo "<p>";
        foreach ($arr as $key => $value) {
            echo $key . " => " . $value . "<br>";
        }
        echo "</p>";
        ?>
    </div>
    <div class="arr">
        <h1>Sorted Array Ascending by value</h1>
        <?php
        asort($arr);
        echo "<p>";
        foreach ($arr as $key => $value) {
            echo $key . " => " . $value . "<br>";
        }
        echo "</p>";
        ?>
    </div>
    <div class="arr">
        <h1>Sorted Array Ascending by key</h1>
        <?php
        ksort($arr);
        echo "<p>";
        foreach ($arr as $key => $value) {
            echo $key . " => " . $value . "<br>";
        }
        echo "</p>";
        ?>
    </div>
    <div class="arr">
        <h1>Sorted Array Descending by value</h1>
        <?php
        arsort($arr);
        echo "<p>";
        foreach ($arr as $key => $value) {
            echo $key . " => " . $value . "<br>";
        }
        echo "</p>";
        ?>
    </div>
    <div class="arr">
        <h1>Sorted Array Descending by key</h1>
        <?php
        krsort($arr);
        echo "<p>";
        foreach ($arr as $key => $value) {
            echo $key . " => " . $value . "<br>";
        }
        echo "</p>";
        ?>
    </div>
</body>

</html>