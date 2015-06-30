<HTML>
        <HEAD>
                <TITLE>PROOF!</TITLE>
        </HEAD>
        <BODY>
                <?PHP
                error_reporting(E_ALL);
ini_set('display_errors', 1);
                        print "Does 5 + 5 = x?<br>";
                        if (5+5 == $x)
                                print "true<br>";
                        else
                                print "false<br>";
                        print "<br>Does x-0 = x?<br>";
                        if (x-0 == $x)
                                print "true<br>";
                        else
                                print "false<br>";
                        print "<br>x = ?, therefore what does x equal?<br>";
                        $x = "?";
                        print $x . "<br>";
                ?>
        </BODY>
</HTML>
