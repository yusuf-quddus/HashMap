# HashMap
Hash Map Data Structure that Hashes

### Hash Function

hash key by adding the digits repeatedly until it ends up being a number between 0 and 9, which will be the index of the data in the hash table. So, a date of 2017-12-04 will reduce as 2+0+1+7+1+2+0+4 = 17 which will further reduce as 1+7 = 8 and its associated data record (name + birthday) will be added to index 8 in the hash table.

### Collision Handling

For collision resolution, use quadratic probing in the same direction always, revert to linear probing. Data Structure capable of link based collision handling

## Authors

* **Yusuf Quddus**
