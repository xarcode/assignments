<h3>
    <?php
    $ymdFormat = "2012-09-12";
    $dmyFormat = date("d-m-Y", strtotime($ymdFormat));
    echo " YYYY-MM-DD--->" . $ymdFormat . "</br>";
    echo "DD-MM-YYYY---->" . $dmyFormat . "</br>";
    ?>
</h3>