<h2>
    <?php
    $str = 'abcde$ddfd @abcd )der]';
    echo "Given string: " . $str . "</br>";
    $output = '';
    for ($i = 0; $i < strlen($str); $i++) {
        if (IntlChar::isalpha("$str[$i]") || $str[$i] == ' ') {
            $output .= $str[$i];
        }
    }
    echo "Updated string: " . $output;
    ;
    ?>
</h2>