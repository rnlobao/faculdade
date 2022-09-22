//
//  AddViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit

class AddViewController: UIViewController {
    @IBOutlet weak var collectionView: UICollectionView!
    @IBOutlet weak var registerButton: UIButton!
    private var viewModel = AddViewModel()
    var theActives: [actives] = []
    
    override func viewDidLoad() {
        setupRegisterButton()
        theActives = viewModel.setupActives()
        setupCollection()
    }
    
    func setupRegisterButton() {
        registerButton.layer.cornerRadius = 20
        registerButton.layer.shadowColor = UIColor.black.cgColor
        registerButton.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        registerButton.layer.shadowRadius = 4.0
        registerButton.layer.shadowOpacity = 0.5
        registerButton.layer.masksToBounds = false
    }
    
    func setupCollection() {
        collectionView.delegate = self
        collectionView.dataSource = self
        
        let layout = UICollectionViewFlowLayout()
        layout.itemSize = CGSize(width: 60.0, height: 60.0)
        
        collectionView.collectionViewLayout = layout
        collectionView.register(ActivesCollectionViewCell.nib(), forCellWithReuseIdentifier: ActivesCollectionViewCell.identifier)
    }
}

extension AddViewController: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 4
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "ActivesCollectionViewCell", for: indexPath) as! ActivesCollectionViewCell
        cell.setupActives(symbolImage: theActives[indexPath.row].image, typeOfActives: theActives[indexPath.row].whatKind)
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        print("You tapped \(indexPath.row + 1)")
    }
}

extension AddViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        return CGSize(width: 60.0, height: 60.0)
    }
    
}

struct actives {
    var image: String
    var whatKind: String
}
