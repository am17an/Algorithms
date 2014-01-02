qs:{$[(count x)<=1;x;(.z.s[x where x < (first x)]),(first x),(.z.s[x where x > (first x)])]}
