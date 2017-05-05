#!/usr/bin/perl

sub average {
  my (@values) = @_;
  my $count = scalar @values;
  my $total = 0;
  $total += $_ for @values;
  return $count ? $total / $count : 0;
}

sub std_dev {
  my ($average, @values) = @_;
  my $count = scalar @values;
  my $std_dev_sum = 0;
  $std_dev_sum += ($_ - $average) ** 2 for @values;
  return $count ? sqrt($std_dev_sum / $count) : 0;
}

foreach $test ( "Blaster", "BlasterRelay" ) {
  foreach $trans ( "tcp", "tor" ) {
    for ($s = 16; $s <= 16777216; $s *= 2) {
      @rates = ();
      foreach $i ( 0, 1, 2 ) {
        $r = ` grep Rate data/${test}_${trans}_${s}_${i}.txt | sed 's/^\\"\\[sink\\] Rate : \\(.*\\)\ pkt\\/s\"\$/\\1/g' `;
        push (@rates, $r);
      }
      @sorted_rates = sort { $a <=> $b } @rates;
      $avg = average(@rates);
      $sd = std_dev($avg, @rates);
      printf "%d,%f,%f,%f,%f,%f\n", $s, $sorted_rates[0], $sorted_rates[1], $sorted_rates[2], $avg, $sd;
    }
  }
}
