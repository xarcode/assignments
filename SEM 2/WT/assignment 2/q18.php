<h3>
    <?php 
        $marks = array(360,310,310,330,313,375,456,111,256);
        echo "Before Sorting::";
        foreach($marks as $values){
            echo $values. " ";
        }
        sort($marks);
        echo "</br>". "After Sorting::";
        foreach($marks as $values){
            echo $values. " ";
        }
    ?>
</h3>