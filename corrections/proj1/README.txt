Jarod Spencer CS490

After unzipping the .gz files to .bed, run the bedtools command
bedtools getfasta -fi path_to_ref/hg38.fa -bed <path_to_narrowBed> -fo <output_path/output#.txt>
With # being replaced by a non-zero int.

Once you have the output#.txt, you can then create the negative version.
You can do this by launching the negative program followed by "-a #" with # being replaced by the same number in output#.txt.
This will create a file called negative#.bed, you will then use the command
bedtools getfasta -fi path_to_ref/hg38.fa -bed negative#.bed -fo negative#.txt
Now negative#.txt is the negative of output1.txt

You will the launch to program called lengthFinder.
To do this you will type the following:
./lengthFinder -a # +/-
the # will be the same number you have been using and the +/- will either be a + or -. 
+ will find the lengths of the output#.txt (Your positive sequence)and output them to length#.txt and - will find the lengths of negative#.txt (your negative sequence) and output them to negLength#.txt
+ will also create seq#.txt of just the isolated sequences and - will create negSeq#.txt of just the isolated negative sequences.

You will then launch the program called avgFinder.
This will work the exact same as lengthFinder where you need to follow up the launch with -a # +/-
It will take in either length#.txt or negLength#.txt and output the average number to avg#.txt and negAvg#.txt respectivly.

Finally you will do the same thing with "sort"
./sort -a # +/-
This will create either final#.txt or negFinal#.txt

