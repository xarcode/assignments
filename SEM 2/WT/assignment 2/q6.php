<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>q6</title>
</head>
<body>
    <table cellpadding="3px" cellspacing="0px" border="1">
        <?php
            for ($i=0; $i < 6; $i++) { 
                echo "<tr>";
                for ($j=0; $j < 5; $j++) { 
                    echo "<td>".$i." * ".$j." = ".$i * $j."</td>";
                }
                echo "</tr>";
            }
        ?>
    </table>
</body>
</html>