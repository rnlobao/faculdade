//
//  ActivesCollectionViewCell.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 20/09/22.
//

import UIKit

class ActivesCollectionViewCell: UICollectionViewCell {

    @IBOutlet weak var backgroundActives: UIView!
    @IBOutlet weak var imageActives: UIImageView!
    @IBOutlet weak var labelActives: UILabel!
    
    func setupActives(symbolImage: String, typeOfActives: String) {
        backgroundActives.backgroundColor = UIColor(named: "light-green-carteirada")
        backgroundActives.layer.cornerRadius = 10
        imageActives.image = UIImage(named: symbolImage)
        labelActives.text = typeOfActives
    }

}
