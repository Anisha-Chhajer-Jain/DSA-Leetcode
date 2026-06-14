function intersection(nums1, nums2) {
    const result = [];

    for (let i = 0; i < nums1.length; i++) {
        let found = false;
        for (let j = 0; j < nums2.length; j++) {
            if (nums1[i] === nums2[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            let alreadyAdded = false;
            for (let k = 0; k < result.length; k++) {
                if (result[k] === nums1[i]) {
                    alreadyAdded = true;
                    break;
                }
            }

            if (!alreadyAdded) {
                result.push(nums1[i]);
            }
        }
    }

    return result;
}
intersection([1,2,2,1], [2,2]);      
intersection([4,9,5], [9,4,9,8,4]);   