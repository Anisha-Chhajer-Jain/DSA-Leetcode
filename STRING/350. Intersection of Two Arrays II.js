// function intersect(nums1, nums2) {
//     let freq = {};
//     let result = [];

//     for (let i = 0; i < nums1.length; i++) {
//         if (freq[nums1[i]] === undefined) {
//             freq[nums1[i]] = 1;
//         } else {
//             freq[nums1[i]]++;
//         }
//     }

//     for (let i = 0; i < nums2.length; i++) {
//         if (freq[nums2[i]] !== undefined && freq[nums2[i]] > 0) {
//             result.push(nums2[i]);
//             freq[nums2[i]]--;
//         }
//     }

//     return result;
// }
// console.log(intersect([1,2,2,1], [2,2])); 
// console.log(intersect([4,9,5], [9,4,9,8,4])); 